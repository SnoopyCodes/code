#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, W; cin >> N >> W;
    vector<int> weights(N);
    vector<int> vals(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> vals[i];
    }

    //ok \/ somehow last time it shouldnt have worked
    //oh so this time its just min 
    vector<int> mw(N * 1000 + 1, W + 1); //hypixel mega balls
    int max_val = N * 1000;
    mw[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = max_val; j >= vals[i]; j--) {
            mw[j] = min(mw[j], mw[j - vals[i]] + weights[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N * 1000 + 1; i++) {
        if (mw[i] == W + 1) { continue; }
        ans = max(i, ans);
    }
    cout << ans << "\n";
}