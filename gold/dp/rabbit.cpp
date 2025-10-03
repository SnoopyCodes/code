#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    auto H = vt<int>(N);
    for (int &u : H) {
        cin >> u;
    }
    auto dp = vt<int>(N + 1, -BIG);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N; j > -1; j--) {
            //we can change this pillar or we don't
            //if we don't, our h[i] - dp[j] <= M
            int can1 = -BIG, can2 = -BIG;
            if (H[i] - dp[j] <= M) {
                can1 = H[i];
            }
            if (j > 0) {
                can2 = dp[j - 1] + M;
            }
            dp[j] = max(can1, can2);
        }
    }
    int ans = 0;
    while (dp[ans] < 0) { ans++; }
    cout << ans << "\n";
}