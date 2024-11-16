#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll sub(ll a, ll b) {
    return ((a - b) % MOD + MOD) % MOD;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

    int N, M, K; cin >> N >> M >> K;
    vector<ll> ways(N);
    vector<ll> change(N);
    ways[0] = M;
    change[0] = M;
    ll total = M;
    for (int i = 1; i < N; i++) {
        total = total * M % MOD;
        ways[i] = (ways[i-1] * M) % MOD;
        change[i] = (ways[i-1] * (M - 1)) % MOD;
        if (i >= K - 1) { ways[i] = sub(ways[i], change[i - K + 1]); }
    }
    cout << sub(total, ways[N - 1]) << "\n";
}