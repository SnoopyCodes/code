#include <bits/stdc++.h>

using namespace std;
const int W = '#';
const int S = 'A';
const int E = 'B';
int laby[1000][1000];
bool visited[1000][1000];
int prevs[1000][1000];
int N, M;
void bfs(int si, int sj) {
    queue<array<int, 2>> vis;
    vis.push({si, sj});
    visited[si][sj] = true;
    prevs[si][sj] = S;
    while (!vis.empty()) {
        auto f = vis.front();
        vis.pop();
        int i = f[0], j = f[1];
        if (laby[i][j] == E) {
            cout << "YES" << endl;
            string s = "";
            while (prevs[i][j] != S) {
                s += (char)prevs[i][j];
                if (prevs[i][j] == 'L') { j++; }
                else if (prevs[i][j] == 'R') { j--; }
                else if (prevs[i][j] == 'U') { i++; }
                else { i--; }
            }
            reverse(s.begin(), s.end());
            cout << s.size() << "\n";
            cout << s << "\n";
            return;
        }
        //now consider our 4 points
        if (j + 1 != M && laby[i][j+1] != W && !visited[i][j+1]) {
            prevs[i][j+1] = 'R';
            visited[i][j+1] = true;
            vis.push({i, j+1});
        }
        if (j - 1 >= 0 && laby[i][j-1] != W && !visited[i][j-1]) {
            prevs[i][j-1] = 'L';
            visited[i][j-1] = true;
            vis.push({i, j-1});
        }
        if (i + 1 != N && laby[i+1][j] != W && !visited[i+1][j]) {
            prevs[i+1][j] = 'D';
            visited[i+1][j] = true;
            vis.push({i+1, j});
        }
        if (i - 1 >= 0 && laby[i-1][j] != W && !visited[i-1][j]) {
            prevs[i-1][j] = 'U';
            visited[i-1][j] = true;
            vis.push({i-1, j});
        }
    }
    cout << "NO" << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    cin >> N >> M;
    array<int, 2> start{0, 0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            laby[i][j] = c;
            if (laby[i][j] == S) { start[0] = i, start[1] = j; }
        }
    }
    bfs(start[0], start[1]);
}