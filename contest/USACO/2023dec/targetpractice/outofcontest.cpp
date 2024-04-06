#include <bits/stdc++.h>

using namespace std;
const int max_n = 1e5;
vector<int> commands;
bitset<2 * max_n> target;
bitset<2 * max_n> r1;
bitset<2 * max_n> r2;
bitset<2 * max_n> def;
bitset<2 * max_n> l1;
bitset<2 * max_n> l2;
vector<vector<int>> hits;
void sim(int start, int index) {
    for (int i = 0; i < commands.size(); i++) {
        start += commands[i];
        if (start < 0 || start >= 2 * commands.size()) { continue; }
        if (commands[i] == 0 && target[start]) {
            hits[2+index][i] = start;
            if (index == -2) { l2[start] = true; }
            else if (index == -1) { l1[start] = true; }
            else if (index == 1) { r1[start] = true; }
            else { r2[start] = true; }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, C; cin >> T >> C;
    hits.resize(5, vector<int>(C));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < T; j++) { hits[i][j] = INT_MIN; }
    }
    for (int i = 0; i < T; i++) {
        int index; cin >> index;
        target[index+C] = true;
    }
    string s; cin >> s;
    commands.resize(C);
    for (int i = 0; i < C; i++) {
        if (s[i] == 'R') { commands[i] = 1; }
        if (s[i] == 'L') { commands[i] = -1; }
    }
    sim(C-2, -2);
    sim(C-1, -1);
    sim(C+1, 1);
    sim(C+2, 2);
    int best = 0;
    int pos = C;
    for (int i = 0; i < C; i++) {  //the commands we have activated are: none YET
        if (commands[i] == -1) {  //move 1 r or 2 r
            int tmp = (def | r1).count() + target[pos];
            best = max(best, tmp);
            tmp = (def | r2).count();
            best = max(best, tmp);
        }
        if (commands[i] == 0) {  //1 r or 1 l
            int tmp = (def | r1).count();
            best = max(best, tmp);
            tmp = (def | l1).count();
            best = max(best, tmp);
        }
        if (commands[i] == 1) {
            int tmp = (def | l2).count();
            best = max(best, tmp);
            tmp = (def | l1).count() + target[pos];
            best = max(best, tmp);
        }
        pos += commands[i];
        if (commands[i] == 0 && target[pos]) {
            def[pos] = true;
        }
        if (hits[0][i] != INT_MIN) { l2[hits[0][i]] = false; }
        if (hits[1][i] != INT_MIN) { l1[hits[1][i]] = false; }
        if (hits[3][i] != INT_MIN) { r1[hits[3][i]] = false; }
        if (hits[4][i] != INT_MIN) { r2[hits[4][i]] = false; }
    }
    best = max(best, (int) def.count());
    cout << best << "\n";
}