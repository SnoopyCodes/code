#include <bits/stdc++.h>

using namespace std;
int diffs[(int)1e6];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    //so you can iterate through all of that
    //you can sort by least cost
    //what to do
    //okay so use a set to say whether we came across something or not
    //afterwards
    //wait these bounds just use a thing to say whether we saw something or not
    //then do work on the smallest
    vector<array<int, 2>> els(N);  //why did i name it this
    for (int i = 0; i < N; i++) {
        cin >> els[i][0];
    }
    for (int i = 0; i < N; i++) {
        cin >> els[i][1];
    }
    for (int i = 0; i < N; i++) {
        int idx = els[i][0] - els[i][1];
        diffs[idx] = min(diffs[idx] != 0 ? diffs[idx] : INT_MAX, els[i][0]);  //threshold
    }
    //now we get the diffs
    //help
    //im so done bro
    //1e6 
}