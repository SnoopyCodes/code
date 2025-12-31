#include <bits/stdc++.h>

using namespace std;
#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for (auto i=a; i<(b); i++)

void solve() {
    int N; cin >> N;
    using vi = vt<int>;
    vi A(N), B(N);
    long ans = 0;
    rep(i,0,N) cin >> A[i], ans += A[i] * A[i] * N * (N - 1) / 2;
    rep(i,0,N) cin >> B[i], ans += B[i] * B[i] * (N * (N - 1)) / 2;



    int MAX = 100 * 100;
    vi dp(MAX + 1); //min cost
    rep(i, 0, N) {
        auto prev = dp;
        rep(j, 0, MAX + 1) {
            
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}