#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //prefix sums doesn't work
    //suppose we start with base at 0 and slide window or something
    //start with the leftmost index
    //no way its N^3 ok its not
    //wait why does dsu work tf
    //well it should be the same thing
    //hmm
    int N, M;
    vector<vector<bool>> grid(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j] == '.';
        }
    }
    //see look it was a queue
    //try processing left
    vector<bool> v = grid[0];
}