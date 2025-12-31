#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  + 7   ;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for(auto i=a; i<(b); i++)

void solve() {
    int N; cin >> N;
    vt<int> A(N); rep(i,0,N) cin >> A[i];

    //dont need anything more than 2 cause of cost function
    vt dp(N, 0);
    dp[0] = A[0] == 0 ? 0 : 1;
    rep(i, 1, N) {
        dp[i] = dp[i-1] + (A[i] == 0 ? 0 : 1);
        if (i > 0 && A[i] == A[i - 1]) {
            dp[i] = min(dp[i], (i > 1 ? dp[i - 2] : 0) + 1);
        }
        if (i > 1) {
            if ((A[i-1] ^ A[i-2]) == A[i]) {
                dp[i] = min(dp[i], (i > 2 ? dp[i - 3] : 0) + 2);
            }
        }
        
    }
    cout << dp[N-1] << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve(); 
}