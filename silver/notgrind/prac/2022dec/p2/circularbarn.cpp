#include <bits/stdc++.h>

using namespace std;
vector<int> rooms;
struct victory {
    int round, room, john;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N;
        rooms.clear(); rooms.resize(N);
        for (int i = 0; i < N; i++) { cin >> rooms[i]; }
        victory nextwin;  //how many iterations, which index, is john
        //check through the whole thing?
        //bruh so everything divisible by 4 is a win for nhoj... but the question is how far into the future that is
        //
        for (int i = 0; i < N; i++) {
            int val = rooms[i];
            bool jwin = val % 4;
            int time = 0;
            if (!jwin) {
                time = val / 4 + 1;  //win before this
                if (nextwin.round > time) { nextwin.round = time; nextwin.room = i; nextwin.john = jwin; }
            }
            if (jwin % 2 == 0) { time = val / 4 + 1;}
            else {

            }
            //find the time it takes to win if john can win
            //multiples of 2 are just val / 4 + 1 also
            //we can check if its prime in sqrt a but that is also too slow??
        }
        if (nextwin.john) { cout << "Farmer John" << "\n"; }
        else { cout << "Farmer Nhoj" << "\n";}
    }

}