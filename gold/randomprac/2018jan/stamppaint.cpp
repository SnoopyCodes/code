#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll pow(int x, int p) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 & 1) { res = res * x % MOD; }
        p /= 2;
        x = x * x % MOD;
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("spainting.in", "r", stdin);
    // freopen("spainting.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    //note that everything is sort of "symmetric" with respect to a certain color
    //observation: there must appear a stamp of some color in the final with length at least K
    //conjecture: after that, all possible combinations of colors can appear in the others
    //but we need to not overcount the multiple lengths...
    //oh crap
    //count the number of possibilities that don't ever have a continuous segment of length K
    //subtract from pow(M, N);
    //NK is quite doable if you do like
    //dp[i][j] = ways to form length of j at i
    //how get faster?
    //dp[1] = M
    //dp[2] = 
    vector<vector<ll>> ways(N + 1, vector<ll>(K + 1));
    ways[1][1] = M;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < K; j++) {
            ways[i+1][j+1] = ways[i][j] % MOD;
            ways[i+1][1] = (ways[i+1][1] + ways[i][j] * (M - 1)) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i < K; i++) {
        ans = (ans + ways[N][i]) % MOD;
    }
    cout << ((pow(M, N) - ans) % MOD + MOD) % MOD << "\n";
}