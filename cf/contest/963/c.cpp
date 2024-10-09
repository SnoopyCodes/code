#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> lights(N);
    for (int i = 0; i < N; i++) {
        cin >> lights[i];
    }
    sort(lights.begin(), lights.end());
    int interval = lights[0];  //praying
    int l = interval, r = interval + K;
    for (int i = 1; i < N; i++) {
        if (lights[i] > interval + K) {  //we need to do actual math
        //ok or binary search if im scared but lets do math
            int diff = lights[i] - interval - K;
            int quotient = (diff / (2 * K)) * 2 * K;
            interval += quotient, l += quotient, r += quotient;  //on time
            while (lights[i] > interval + K) {  //idk
                interval += 2 * K, l += 2 * K, r += 2 * K;
            }
        }
        int l1 = lights[i], r1 = lights[i] + K;
        if (r-1 < l1 || l > r1-1) { cout << -1 << "\n"; return; }
        l = max(l, l1), r = min(r, r1);
    }
    cout << l << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}