#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int S, N; cin >> S >> N;
    vector<ll> value(S + 1, -1);
    value[0] = 0;
    for (int i = 0; i < N; i++) {
        int v, w, c; cin >> v >> w >> c;
        vector<ll> tmp = value;
        for (int j = 0; j < w; j++) {
            deque<ll> dq;
            for (int k = j; k < S - w + 1; k += w) {
                int idx = (k - j) / w;
                //insert
                while (!dq.empty() && dq.back() < value[k] - idx * v) { dq.pop_back(); }
                dq.push_back(value[k] - idx * v);
                if (idx >= c) {
                    int ok = k - c * w;
                    int oidx = (ok - j) / w;
                    //
                    if (!dq.empty() && dq.front() == value[ok] - oidx * v) { dq.pop_front(); }
                }
                if (dq.empty()) { continue; }
                ll best = dq.front();
                tmp[k + w] = max(tmp[k + w], best + (idx + 1) * v);
            }
        }
        value = tmp;
    }
    ll ans = 0;
    for (int i = 0; i < S + 1; i++) {
        ans = max(value[i], ans);
    }
    cout << ans << "\n";
}