#include <bits/stdc++.h>

using namespace std;
using point = array<int, 2>;
vector<vector<int>> visited;
vector<vector<bool>> lol;
queue<point> trav;
const int done = 2;
const int lit = 1;
int N;
int cnt = 1;
void flood(int r, int c) {
    if (visited[r][c] == lit) { visited[r][c] = done; trav.push({r, c}); }
    lol[r][c] = true;
    r++;
    if (r < N && visited[r][c] && !lol[r][c]) { flood(r, c); }
    r -= 2;
    if (r > -1 && visited[r][c] && !lol[r][c]) { flood(r, c); }
    r++; c++;
    if (c < N && visited[r][c] && !lol[r][c]) { flood(r, c); }
    c -= 2;
    if (c > -1 && visited[r][c] && !lol[r][c]) { flood(r, c); }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int M; cin >> N >> M;
    visited.resize(N, vector<int>(N));
    vector<vector<vector<point>>> yes(N, vector<vector<point>>(N));  //yeehaw
    for (int i = 0; i < M; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
        yes[a][b].push_back({c, d});
    }
    //okay we need to be very careful
    trav.push({0, 0});
    visited[0][0] = done;
    while (!trav.empty()) {
        int r = trav.front()[0], c = trav.front()[1];
        trav.pop();
        for (point p : yes[r][c]) {
            if (!visited[p[0]][p[1]]) { //unlit
                visited[p[0]][p[1]]++;
                cnt++;
            }
        }

        //floodfill
        lol.clear();
        lol.resize(N, vector<bool>(N));
        flood(0, 0);
    }
    cout << cnt << "\n";
}