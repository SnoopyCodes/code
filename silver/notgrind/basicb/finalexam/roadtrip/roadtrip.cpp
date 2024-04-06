#include <bits/stdc++.h>

using namespace std;
vector<int> move1;
vector<int> move2;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    move1.resize(N); move2.resize(M); 
    for (int i = 0; i < N; i++) {
        cin >> move1[i];
        string dir; cin >> dir;
        if (dir[0] == 'L') { move1[i] *= -1; }
    }
    for (int i = 0; i < M; i++) {
        cin >> move2[i];
        string dir; cin >> dir;
        if (dir[0] == 'L') { move2[i] *= -1; }
    }
    int pos1 = 0, act1 = 0;
    int pos2 = 0, act2 = 0;
    int c = 0;
    //how do we move the 2 cows quickly?
    int time = 0;
    while (act1 != N && act2 != M) {
        //choose an act to perform
        bool oneless = pos1 < pos2;
        bool twoless = pos2 < pos1;
        if (abs(move1[act1]) < abs(move2[act2])) {  //move1
            pos1 += move1[act1];
            if (move2[act2] < 0) {  //if left
                pos2 -= abs(move1[act1]);  //move these units to the right
                move2[act2] += abs(move1[act1]); //reduce the time spent moving
            }   else {  //to right
                pos2 += abs(move1[act1]);
                move2[act2] -= abs(move1[act1]);
            }
            act1++;
        }   else if (abs(move1[act1]) > abs(move2[act2])) {
            pos2 += move2[act2];
            if (move1[act1] < 0) {
                pos1 -= abs(move2[act2]);
                move1[act1] += abs(move2[act2]);
            }   else {
                pos1 += abs(move2[act2]);
                move1[act1] -= abs(move2[act2]);
            }
            act2++;
        }   else {  //just move both concurrently
            pos1 += move1[act1];
            pos2 += move2[act2];
            act1++; act2++;
        }
        if (oneless && pos1 >= pos2) { c++; }
        else if (twoless && pos2 >= pos1) { c++; }
    }
    while (act1 != N) {
        bool oneless = pos1 < pos2;
        bool twoless = pos2 < pos1;
        //move act1
        pos1 += move1[act1];
        act1++;
        if (oneless && pos1 >= pos2) { c++; }
        else if (twoless && pos2 >= pos1) { c++; }
    }
    while (act2 != M) {
        bool oneless = pos1 < pos2;
        bool twoless = pos2 < pos1;
        pos2 += move2[act2];
        act2++;
        if (oneless && pos1 >= pos2) { c++; }
        else if (twoless && pos2 >= pos1) { c++; }
    }
    cout << c << "\n";

}