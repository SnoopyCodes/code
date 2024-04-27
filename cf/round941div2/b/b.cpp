#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j];
        }
    }
    //so we need to find 2 xs, ys, where colors are equal
    //wait but to find if its possible?
    //we should first chekc if its possible for white
    //uhhhhh
    //lets say we have black on the left bottom corner
    //we want to be able to get to the other side
    //AND get to the top
    //therefore if we just check the sides then we have it?
    //now its impl
    //so check the 0 0 corner and the opposite sides
    //wait basically just check that the two opposing sides are not FULL, opposing colors?
    //i think that is the rule
    char lccol = grid[0][0];
    bool lcall = true;
    for (int i = 0; i < N; i++) {
        if (grid[i][0] != lccol) {
            lcall = false; break;
        }
    }
    char rccol = grid[0][M-1];
    bool rcall = true;
    for (int i = 0; i < N; i++) {
        if (grid[i][M-1] != rccol) { rcall = false; break;}
    }
    char urrow = grid[0][0];
    bool urall = true;
    for (int i = 0; i < M; i++) {
        if (grid[0][i] != urrow) { urall = false; break; }
    }
    char drrow = grid[N-1][0];
    bool drall = true;
    for (int i = 0; i < M; i++) {
        if (grid[N-1][i] != drrow) { drall = false; break; }
    }
    if (lcall && rcall && lccol != rccol) {
        cout << "NO" << "\n";
    }   else if (drall && urall && drrow != urrow) {
        cout << "NO" << "\n";
    }   else {
        cout << "YES" << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}