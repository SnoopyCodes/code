#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int S, N; cin >> S >> N;
    vector<ll> value(S + 1, -1);
    value[0] = 0;
    for (int i = 0; i < N; i++) {
        int v, w, c; cin >> v >> w >> c;
        if (1LL * c * w >= S) {
            // Treat as unbounded knapsack item
            for (int s = w; s <= S; s++) {
                if (value[s - w] != -1) {
                    value[s] = max(value[s], value[s - w] + v);
                }
            }
        } else {
            // Use binary representation to split counts
            vector<int> nums;
            int cnt = c;
            for (int k = 1; cnt > 0; k <<= 1) {
                int num = min(k, cnt);
                nums.push_back(num);
                cnt -= num;
            }
            for (int num : nums) {
                int total_w = num * w;
                int total_v = num * v;
                for (int s = S; s >= total_w; s--) {
                    if (value[s - total_w] != -1) {
                        value[s] = max(value[s], value[s - total_w] + total_v);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= S; i++) {
        ans = max(ans, value[i]);
    }
    cout << ans << "\n";
}
