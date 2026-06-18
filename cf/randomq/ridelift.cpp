#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K, A, B; cin >> N >> A >> B >> K; A--; B--;
    //try reading problem statement maybe?
    //this is really easy with segment tree?
    vt<int> dp(N);
    dp[A] = 1;
    while (K --> 0) {
        auto darr = vt<int>(N + 1);
        for (int i = 0; i < N; i++) {
            int d = abs(B - i);
            //from [i - d + 1, i + d - 1]
            (darr[max(i - d + 1, 0)] += dp[i]) %= P;
            (darr[min(i + d, N)] -= dp[i]) %= P;
            //we cannot stay at ourselves
            (darr[i] -= dp[i]) %= P;
            (darr[i + 1] += dp[i]) %= P;
        }
        int64_t cur = 0;
        for (int i = 0; i < N; i++) {
            (cur += P + darr[i]) %= P;
            dp[i] = cur;
        }
    }
    cout << accumulate(begin(dp), end(dp), 0LL) % P << endl;
}