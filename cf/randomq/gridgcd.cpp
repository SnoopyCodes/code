#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int N, M; cin >> N >> M;
    vt<vt<int>> grid(N, vt<int>(M));
    vt dp(N, vt<int>(M));
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> grid[i][j];
        }
    }

    rep(i, 0, N) {
        rep(j, 0, M) {
            if (i) {
                
            }
            if (j) {
                
            }
        }
    }
    int ans = 1;
    
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) { solve(); }
}