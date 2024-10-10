#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll bits(ll x) { return __builtin_popcountll(x); }
int main() {
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
    for (int mask = 0; mask < 1 << r; mask++) {
        ll options = 0;
        for (int b = 0; b < r; b++) {
            if (mask & 1 << b) { options |= reach[b + l]; }
        }
        bool valid = true;
        for (int b = 0; b < r; b++) {
            if (mask & 1 << b && options & 1LL << b + l) { valid = false; break; }
        }
        if (valid) { right.push_back((ll)mask << l); }
    }

    vector<ll> dp(1 << l);
    vector<ll> res(1 << l);
    for (ll rset : right) {
        //this is a recalculation
        ll options = 0;
        for (int b = 0; b < N; b++) {
            if (rset & 1LL << b) { options |= reach[b]; }
        }
        for (int b = l; b < N; b++) {
            if (options & 1LL << b) { options ^= 1LL << b; }
        }
        ll invert = ((1LL << l) - 1) ^ options;  //idk what happens if we xor an int with a ll
        if (bits(res[invert]) < bits(rset)) { res[invert] = rset; }
    }

    int ans = 0;
    ll ans_set = 0;
    for (int mask = 0; mask < 1 << l; mask++) {
        if (ans < bits(dp[mask]) + bits(res[mask])) {
            ans = bits(dp[mask]) + bits(res[mask]);
            ans_set = dp[mask] | res[mask];
        }

        ll options = 0;
        for (int b = 0; b < l; b++) {
            if (mask & 1 << b) {  //we can reach all that this reaches
                options |= reach[b];
            }
        }

        bool valid = true;
        for (int b = 0; b < l; b++) {
            if (mask & 1 << b && options & 1 << b) { valid = false; break; }
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
            if (bits(dp[mask | 1 << b]) < bits(dp[mask])) {
                dp[mask | 1 << b] = dp[mask];
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