#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //dude im lowk gonna stop at some point
    int N, W; cin >> N >> W;
    vector<int> best(W + 1, -1);
    best[0] = 0;
    for (int i = 0; i < N; i++) {
        int v, w, f; cin >> w >> v >> f;
        for (int j = 0; j < f; j++) {
            for (int k = W; k > -1; k--) {
                if (k + w > W || best[k] == -1) { continue; }
                best[k + w] = max(best[k + w], best[k] + v);
            }
        }
    }
    cout << *max_element(best.begin(), best.end());
}