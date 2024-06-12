#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, D; cin >> N >> K >> D;
    ll total = 0;
    vector<ll> dp(N + 1);  //this stores the different sums we currently have
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        //for every one of these sums, move up 1...K
        for (int j = 1; j < K + 1; j++) {
            if (j + i > N) { break; }
            dp[i + j] = (dp[i + j] + dp[i]) % MOD;
        }
    }
    vector<ll> fake(N + 1);
    fake[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < D; j++) {
            if (i + j > N) { break; }
            fake[i + j] = (fake[i + j] + fake[i]) % MOD;
        }
    }
    //oh our modulo is confusing lmfao
    cout << (dp[N] - fake[N] + MOD) % MOD;
}
//isnt this just dp hello??
//classical dp??
//wait
//one edge of weight d
//bruh
//bruh brh bruh
//wait then subtract the number to with weights less than d