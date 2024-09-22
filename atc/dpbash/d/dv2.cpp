#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, W; cin >> N >> W;
    vector<int> weights(N);
    vector<int> vals(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> vals[i];
    }
    //nw
    //dp[i][j] = max val with items 0...i and j
    vector<ll> best(W + 1, -1);
    best[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= weights[i]; j--) {
            if (best[j - weights[i]] == -1) { continue; }
            best[j] = max(best[j], best[j - weights[i]] + vals[i]);
        }
    }
    cout << *max_element(best.begin(), best.end());
}