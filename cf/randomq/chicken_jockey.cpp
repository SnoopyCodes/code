#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int N; cin >> N;
    vt<int> H(N);
    long ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        ans += max(0, H[i] - i);
        H[i] = min(H[i], i);
    }
    //always cut from the back
    //dp on how much we can save
    //set to min
    //dp on cost to kill for those up to i
    vt<ll<2>> dp(N, { INF, INF }); //[0] is straight kill this one, [1] is use smth from before
    dp[0][0] = 0;
    for (int i = 1; i < N; i++) {
        //[0]: we kill this
        //H[i] + any way to kill the previous 2.
        dp[i][0] = H[i] + min(dp[i-1][0], dp[i-1][1]);
        //[1]: we die to fall damage, at least partially.
        //rainboy 
        //the thing is there is in fact a 
 
        dp[i][1] = min(dp[i-1][0], dp[i - 1][1] + H[i] - 1);
    }
    ans += ranges::min(dp[N-1]);
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}