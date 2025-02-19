#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=(s);x!=(e);(s)<(e)?x++:x--)
#define rep2(x,e) rep3(x,e>0?0:-(e)-1,e>0?e:-1)

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    vec<vec<int>> grid(N, vec<int>(M));
    vec<bool> done(N * M + 1);
    set<int> freq;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            freq.insert(grid[i][j]);
            if (i) {
                if (grid[i][j] == grid[i-1][j] && !done[grid[i][j]]) {
                    done[grid[i][j]] = true;
                    cnt++;
                }
            }
            if (j) {
                if (grid[i][j] == grid[i][j-1] && !done[grid[i][j]]) {
                    done[grid[i][j]] = true;
                    cnt++;
                }
            }
        }
    }
    cnt += freq.size() - 1;
    for (bool x : done) {
        if (x) { cnt--; break; }
    }
    cout << cnt << "\n";
    //does it matter what color we choose?
    //yes it does
    //without the restriction, is number of colors - 1
    //now we just choose the color with any restriction and mark that as having an extra
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}