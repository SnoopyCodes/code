//https://oj.uz/problem/view/IZhO14_bank

#include <bits/stdc++.h>

using namespace std;
vector<int> salaries;
vector<int> notes;
vector<vector<int>> sums;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //use bitmask dp on bitmask dp :skull:
    //precalculate all the different bitmasks required for each individual one
    //then when we run a xor we can see if there is any overlap
    salaries.resize(N);
    notes.resize(M);
    sums.resize(1001);
    for (int i = 0; i < N; i++) {
        cin >> salaries[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> notes[i];
    }
    //find the bitmasks
    for (int mask = 0; mask < 1 << M; mask++) {
        int sum = 0;
        for (int b = 0; b < M; b++) {
            if (!(mask & 1 << b)) { continue; }
            sum += notes[b];
        }
        if (sum > 1000) { continue; }
        sums[sum].push_back(mask);
    }
    //now the hard part: form all possible stuff
    //i am trll
    //im betting its a better idea to use sets here?
    vector<set<int>> possible(1 << N);  //bitmasks which are possible, with bitmasks of notes
    possible[0].insert(0);
    for (int mask = 1; mask < 1 << N; mask++) {
        for (int b = 0; b < N; b++) {
            if (!(mask & 1 << b)) { continue; }
            int from = mask ^ 1 << b;
            for (int new_m : sums[salaries[b]]) {
                for (int old_m : possible[from]) {  //ways to get to old
                    if (new_m & old_m) { continue; }  //if overlap goodbye
                    possible[mask].insert(new_m ^ old_m);
                }
            }
        }
    }
    bool valid = possible[(1 << N) - 1].size() > 0;
    cout << (valid ? "YES" : "NO") << "\n";
}