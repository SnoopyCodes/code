#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
constexpr int B = 60;
int pre[B];
int solve(int x) {
    int maxb = -1;
    for (int b = B; b > -1; b--) {
        if (x >> b & 1) { maxb = b; break; }
    }
    if (__builtin_popcountll(x) == 1) {
        return pre[maxb];
    }
    return pre[maxb] + (1LL << maxb) + solve(x ^ 1LL << maxb);
    
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    /*
    first, find an upper bound. 1 + 2 + ... n - 1 (con to 0)
    go from the largest bit. 
    is this proven to be the best?
    uhh if n = 2^k, yes we do get an optimal solution
    but what about the remaining bits?
    
    */

    pre[0] = 0;
    rep(i, 1, B) {
        pre[i] = pre[i - 1] * 2 + (1LL << i - 1);
    }

    cout << solve(N) << "\n";
    //thus we solve to 1 << maxbit(N)
    //but we have the remaining ones to do...
    
}