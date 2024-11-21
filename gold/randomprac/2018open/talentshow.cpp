#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int N, W; cin >> N >> W;
    vector<int> talent(N), weight(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> talent[i];
    }
    //sigma talent / sigma weight = x
    //sigma talent - sigma weight * x >= 0
    //y = 1000x
    //1000 * sigma talent - sigma weight y >= 0
    int s = 0, e = 1e9;
    while (s + 1 < e) {  //find maximal s that works
        int m = (s + e) / 2;
        //1000 * sigma talent - sigma weight y >= 0
        //1000 * talent - y * weight
        vector<ll> score(W + 1, -1e18);
        score[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = W; j > -1; j--) {
                if (score[j] == -1e18) { continue; }
                if (j + weight[i] >= W) {
                    score[W] = max(score[W], score[j] + 1000 * talent[i] - (ll) m * weight[i]);
                }   else {
                    score[j + weight[i]] = max(score[j + weight[i]], score[j] + 1000 * talent[i] - (ll) m * weight[i]);
                }
            }
        }
        if (score[W] >= 0) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}