#include <bits/stdc++.h>

#include <conio.h>
#include <windows.h>

using namespace std; //lets go bad practice

template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long uld(long long a, long long b) { return uniform_int_distribution<long long>(a, b)(rng); }

array<string, 6> RISING_DIE {
    "Banish top card of any location",
    "Reveal and place top deck card anywhere",
    "Gain sovereign",
    "+Helium",
    "+Fleet",
    "+Influence"
};

struct Player { //wfztx reference?
    string name, house;
    array<int, 3> res;
    double clock;
    Player(string n, string h, double t) : name(n), house(h), clock(t), res{} {}

    void change_resource(int i, int d) {
        res[i] += d;
    }
    bool end_game() {
        return (res[0] >= 7) + (res[1] >= 7) + (res[2] >= 7) >= 2;
    }
    void change_clock(double x) {
        clock += x / 1000;
    }
};

string input_buffer;
bool running = true;

vt<Player> players;

int nround;
int turn;
bool paused;

int num_players;
int player_time;
int increment;

array<int, 97 + 26> stupid_map_char_to_indices; //put char, get index

regex MOVE;

ifstream fin("game.txt");

//main thread
void game_init() {
    nround = 1;
    turn = 0;
    paused = true;
    fin >> num_players >> player_time >> increment;
    players.reserve(num_players);

    { string z = ""; getline(fin, z); } //like a scanner Lol
    assert(1 <= num_players && num_players <= 6);

    vt<string> HOUSES = {
        "APOLLO",
        "CERES",
        "DIANA",
        "JUPITER",
        "MARS",
        "MINERVA"
    };

    bool apollo = false;
    int apolloi = -1;
    for (int i = 0; i < num_players; i++) {
        string n; getline(fin, n);
        string h = HOUSES[uld(0, size(HOUSES) - 1)];
        if (h == "APOLLO") { apollo = true; apolloi = i; }
        players.push_back({ n, h, player_time });
        HOUSES.erase(ranges::find(HOUSES, h));
    }

    if (apollo) { swap(players[0], players[apolloi]); }
    ranges::shuffle(begin(players) + apollo, end(players), rng);

    ranges::fill(stupid_map_char_to_indices, -1);
    stupid_map_char_to_indices['f'] = 0;
    stupid_map_char_to_indices['h'] = 1;
    stupid_map_char_to_indices['i'] = 2;

    MOVE = regex("([1-6][fhiFHI]([\\+-]?[0-9])){0,}[sS]?"); //to find a move
}

void process() {
    string ACTION = input_buffer;
    if (regex_match(ACTION, MOVE) && ACTION.size() > 0) {
        // if (paused) { continue; } //as it is the only way to fix undos rn
        bool take_sov = ACTION.back() == 's';
        if (take_sov) { ACTION.pop_back(); }
        while (!ACTION.empty()) {
            int delta = ACTION.back() - '0';
            ACTION.pop_back();

            char c = ACTION.back();
            if (c == '-') {
                delta *= -1;
            }
            if (c == '-' || c == '+') {
                ACTION.pop_back();
            }
            
            int resource = stupid_map_char_to_indices[ACTION.back()];
            ACTION.pop_back();

            int player = ACTION.back() - '1';
            players[player].change_resource(resource, delta);
            ACTION.pop_back();
        }

        if (take_sov) {
            string h = players[turn].house;
            if (h == "MARS") { players[turn].change_resource(1, 1); }
            else if (h == "JUPITER") { players[turn].change_resource(0, 1); }
            else if (h == "DIANA") { players[turn].change_resource(2, 1); }
            else if (h == "MINERVA") {
                int roll = uld(0, 4);
                if (roll >= 2) { //the indexing doesn't matter.
                    roll -= 2;
                    players[turn].change_resource(roll, 1);
                }
                //@TODO BROADCAST ROLL TO DISPLAY
            }
        }
    }   else if (ACTION == "p") {
        paused ^= 1;
    }   else if (ACTION == " ") {
        if (paused) { return; }

        players[turn].change_clock(increment * 1000);

        bool gg = false;
        for (Player p : players) {
            gg |= p.end_game();
        }
        if (gg) {
            running = false;
        }

        turn++;
        if (turn == num_players) {
            nround++;
            turn = 0;
        }
    }   else if (ACTION == "u") {
        
    }   else if (ACTION == "end") {
        running = false;
    }
}

//begin chatgpt
//implements a framebuffer i don't want to learn how to do
//the multithreading is interesting though

const int HEIGHT = 20;
const int WIDTH = 60;

// Framebuffer for game rendering
CHAR_INFO buffer[HEIGHT * WIDTH];
COORD bufferSize = { WIDTH, HEIGHT };
COORD zero = {0, 0};
SMALL_RECT writeRegion = {0, 0, WIDTH-1, HEIGHT-1};

// Input line (separate row)
CHAR_INFO inputRow[WIDTH];
SMALL_RECT inputRegion = {0, HEIGHT, WIDTH - 1, HEIGHT};

int cursor_pos = 0;
mutex mtx;

HANDLE hout;

void draw_framebuffer() {
    WriteConsoleOutputA(hout, buffer, bufferSize, zero, &writeRegion);
}

void draw_input_line() {
    // Clear the row
    for (int i = 0; i < WIDTH; i++) {
        inputRow[i].Char.AsciiChar = ' ';
        inputRow[i].Attributes = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
    }

    string prompt = "Command: ";
    for (int i = 0; i < (int)prompt.size() && i < WIDTH; i++) {
        inputRow[i].Char.AsciiChar = prompt[i];
    }

    for (int i = 0; i < (int)input_buffer.size() && i + prompt.size() < WIDTH; i++) {
        inputRow[i + prompt.size()].Char.AsciiChar = input_buffer[i];
    }

    WriteConsoleOutputA(hout, inputRow, { (SHORT)WIDTH, 1 }, zero, &inputRegion);

    // Move cursor to correct place
    COORD curPos = { (SHORT)(prompt.size() + cursor_pos), (SHORT)HEIGHT };
    SetConsoleCursorPosition(hout, curPos);
}

int read_key() {
    int c = _getch();
    if (c == 0 || c == 224) return 1000 + _getch();
    return c;
}

void input_thread() {
    while (running) {
        if (_kbhit()) {
            int key = read_key();
            lock_guard<mutex> lock(mtx);
            if (key == '\r') {
                if (input_buffer == "quit") running = false;
                //input_buffer is what we now wish to process, yes
                process();
                input_buffer.clear();
                cursor_pos = 0;
                continue;
            }

            if (key == 8) {
                if (cursor_pos > 0) {
                    input_buffer.erase(cursor_pos - 1, 1);
                    cursor_pos--;
                }
                continue;
            }

            if (key == 1000 + 83) {
                if (cursor_pos < (int)input_buffer.size())
                    input_buffer.erase(cursor_pos, 1);
                continue;
            }

            if (key == 1000 + 75) {
                if (cursor_pos > 0) cursor_pos--;
                continue;
            }

            if (key == 1000 + 77) {
                if (cursor_pos < (int)input_buffer.size()) cursor_pos++;
                continue;
            }

            if (key == 1000 + 71) {
                cursor_pos = 0;
                continue;
            }

            if (key == 1000 + 79) {
                cursor_pos = input_buffer.size();
                continue;
            }

            if (32 <= key && key <= 126) {
                input_buffer.insert(input_buffer.begin()+cursor_pos, (char)key);
                cursor_pos++;
            }
        }
        this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void render_thread() {
    while (running) {
        draw_framebuffer();

        {
            lock_guard<mutex> lock(mtx);
            draw_input_line();
        }

        this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

int main() {
    game_init();
    hout = GetStdHandle(STD_OUTPUT_HANDLE);

    // Init framebuffer
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            buffer[y * WIDTH + x].Char.AsciiChar = ' ';
            buffer[y * WIDTH + x].Attributes = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
        }
    }

    // Init input row
    for (int i = 0; i < WIDTH; i++) {
        inputRow[i].Char.AsciiChar = ' ';
        inputRow[i].Attributes = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
    }

    thread t_in(input_thread);
    thread t_rn(render_thread);

    int x = 0;
    while (running) {
        buffer[10 * WIDTH + x].Char.AsciiChar = '*';
        buffer[10 * WIDTH + (x + WIDTH - 1) % WIDTH].Char.AsciiChar = ' ';

        x = (x + 1) % WIDTH;
        this_thread::sleep_for(std::chrono::milliseconds(30));
    }

    t_in.join();
    t_rn.join();
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\033[?25h";        // restore cursor
    cout << "\033[?1049l";      // restore screen buffer (if used)
    COORD pos = {0, HEIGHT + 2};
SetConsoleCursorPosition(h, pos);

    cout << "GG" << "\n";
}
