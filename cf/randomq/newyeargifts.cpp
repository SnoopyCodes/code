#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for (auto i=a; i<(b); i++)
void solve() {
    int N, M; cin >> N >> M;
    long long K; cin >> K;
    vt<int> f(M);
    vt<int> S(M); rep(i, 0,  M) cin >> S[i], f[S[i] - 1]++;
    vt<vt<int>> want(M);
    vt<ii<3>> F(N); rep(i, 0, N) cin >> F[i][0] >> F[i][1] >> F[i][2], K -= F[i][1],
                                     want[F[i][0] - 1].add(F[i][2] - F[i][1]);

    //bruh the name of the game has changed
    //this is actually just trivial
    //continue iterating over M
    multiset<int> s;
    int ans = 0;
    rep(i, 0, M) {
        for (auto x : want[i]) {
            s.insert(x);
        }
        while (f[i] && size(s)) {
            f[i]--;
            ans++;
            s.erase(s.find(*s.rbegin()));
        }
    }
    for (int x : s) {
        if (K >= x) {
            K -= x;
            ans++;
        }   else {
            break;
        }
    }
    cout << ans << "\n";
    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}