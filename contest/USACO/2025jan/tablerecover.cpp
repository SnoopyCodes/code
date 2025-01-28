#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> table(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
    //choose some integers to swap
    int MV = 2 * N;
    //brute force all ways to do 1 and 2: 40320^2 does not quite work, sadly
    //wait for N <= 8 surely this is possible
    //give each a position 1...N
    //how do we do this?
    //try for 700
    //
}