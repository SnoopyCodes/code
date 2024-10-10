#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
ll bits(ll x) {
    return __builtin_popcountll(x);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<ll> reach(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        reach[u] |= 1LL << v;
        reach[v] |= 1LL << u;
    }
    //meet in the middle probably works

    //calculate 
    vector<ll> right;
    int r = N - N / 2;
    int l = N / 2;
    for (int mask = 0; mask < 1LL << r; mask++) {
        ll options = 0;
        for (int b = 0; b < r; b++) {
            if (mask & 1LL << b) {  //we can reach all that this reaches
                options |= reach[b + l];
            }
        }
        bool valid = true;
        for (int b = 0; b < r; b++) {
            if (mask & 1LL << b && options & 1LL << b + l) { valid = false; break; }
        }
        if (valid) { right.push_back((ll)mask << l); }
    }

    vector<ll> dp(1LL << l);
    vector<ll> res(1LL << l);
    for (ll rset : right) {
        //this is a recalculation
        ll options = 0;
        for (int b = 0; b < N; b++) {
            if (rset & 1LL << b) {  //we can reach all that this reaches
                options |= reach[b];
            }
        }
        for (int b = l; b < N; b++) {
            if (options & 1LL << b) { options ^= 1LL << b; }
        }
        ll mask = ((1LL << l) - 1) ^ options;
    // Update 'res' only if the new rset has more nodes
    if (bits(res[mask]) < bits(rset)) {
        res[mask] = rset;
    }
    }

    int ans = 0;
    ll ans_set = 0;
    for (int mask = 0; mask < 1LL << l; mask++) {
        if (ans < bits(dp[mask]) + bits(res[mask])) {
            ans = bits(dp[mask]) + bits(res[mask]);
            ans_set = dp[mask] | res[mask];
        }

        ll options = 0;
        for (int b = 0; b < l; b++) {
            if (mask & 1LL << b) {  //we can reach all that this reaches
                options |= reach[b];
            }
        }

        bool valid = true;
        for (int b = 0; b < l; b++) {
            if (mask & 1LL << b && options & 1LL << b) { valid = false; break; }
        }
        if (valid) {
            if (bits(dp[mask]) < bits(mask)) {
                dp[mask] = mask;
            }
            if (ans < bits(dp[mask]) + bits(res[mask])) {
                ans = bits(dp[mask]) + bits(res[mask]);
                ans_set = dp[mask] | res[mask];
            }
        }
        for (int b = 0; b < l; b++) {
            if (bits(dp[mask | 1LL << b]) < bits(dp[mask])) {
                dp[mask | 1LL << b] = dp[mask];
            }
        }
    }
    cout << ans << "\n";
    for (int b = 0; b < N; b++) {
        if (ans_set & 1LL << b) {
            cout << b << " ";
        }
    }
}