#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int W, N, T; cin >> W >> N >> T;
    //bruh
    vector<vector<array<int, 2>>> group(T);
    for (int i = 0; i < N; i++) {
        int w, c, g; cin >> w >> c >> g; g--;
        group[g].push_back({w, c});
    }
    vector<int> best(W + 1, -1);
    best[0] = 0;
    for (int i = 0; i < T; i++) {
        for (int j = W; j > -1; j--) {
            if (best[j] == -1) { continue; }
            for (auto [w, c] : group[i]) {
                if (j + w > W) { continue; }
                best[j + w] = max(best[j + w], best[j] + c);
            }
        }
    }
    cout << *max_element(best.begin(), best.end()) << "\n";
}