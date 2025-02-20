#include <bits/stdc++.h>

#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using namespace std;

vec<int> dr{1, -1, 0, 0}, dc{0, 0, -1, 1};
int N, sz;
vec<vec<int>> grid;
arr<vec<vec<bool>>, 2> vis;
bool ob (int r, int c) {
    return r < 0 || c < 0 || r == N || c == N;
}
void flood(int r, int c, int i = -1, int j = -1) {
    sz++;
    int ind = j != -1;
    vis[ind][r][c] = true;
    rep(d, 4) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (ob(nr, nc)) { continue; }
        if (!vis[ind][nr][nc] && (grid[nr][nc] == i || grid[nr][nc] == j)) {
            flood(nr, nc, i, j);
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    cin >> N;
    grid.resize(N, vec<int>(N));
    rep(i, 2) {
        vis[i].resize(N, vec<bool>(N));
    }
    vec<int> col(1e6 + 1);
    rep(i, N) {
        rep(j, N) {
            cin >> grid[i][j];
            col[grid[i][j]]++;
        }
    }
    int one = 1;
    int two = 2;
    rep(i, N) {
        rep(j, N) {
            if (!vis[0][i][j]) {
                sz = 0;
                flood(i, j, grid[i][j]);
                one = max(one, sz);
            }
            rep(k, 2) {
                int nr = i + dr[1+k];
                int nc = j + dc[1+k];
                if (ob(nr, nc)) { continue; }
                if (grid[i][j] == grid[nr][nc]) { continue; }
                if (two >= col[grid[i][j]] + col[grid[nr][nc]]) { continue; }  //VERY NECESSARY
                sz = 0;
                vis[1].clear();
                vis[1].resize(N, vec<bool>(N));
                flood(i, j, grid[i][j], grid[nr][nc]);
                two = max(two, sz);
            }

        }
    }
    cout << one << "\n";
    cout << two << "\n";
}