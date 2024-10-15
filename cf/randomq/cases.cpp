#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, C, K; cin >> N >> C >> K;
    string s; cin >> s;
    //so we need to select a set k such that all characters are within
    //distance k of each other
    //can we not brute force 2^18 * 324?
    //262144 * 300
    //75e6 should pass
    vector<int> freq(C);
    for (int i = 0; i < K; i++) {
        freq[s[i] - 65]++;
    }
    vector<bool> bad(1 << C);
    auto make_mask = [&]() {
        int res = 0;
        for (int b = 0; b < C; b++) {
            res |= (freq[b] > 0) << b;
        }
        bad[(1 << C) - 1 ^ res] = true;
    };
    make_mask();
    for (int i = K; i < N; i++) {
        freq[s[i - K] - 65]--;
        freq[s[i] - 65]++;
        make_mask();
    }
    //why is this line necessary?
    bad[(1 << C) - 1 - (1 << (s.back() - 'A'))] = true;
    int ans = C;
    for (int mask = (1 << C) - 1; mask > -1; mask--) {
        if (!bad[mask]) { ans = min(ans, __builtin_popcount(mask)); }
        for (int b = 0; b < C; b++) {
            if (mask & 1 << b == 0) { continue; }
            bad[mask ^ 1 << b] = bad[mask ^ 1 << b] | bad[mask];
        }
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}