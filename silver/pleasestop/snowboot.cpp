#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int N, B; cin >> N >> B;
    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }
    vector<array<int, 2>> boot(B);
    for (int i = 0; i < B; i++) {
        cin >> boot[i][0] >> boot[i][1];
    }
    vector<int> reach(N, B);  //highest boot reachable with
    reach[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = reach[i]; j < B; j++) {
            auto [d, s] = boot[j]; //depth, step idk why they swapped it
            if (d < height[i]) { continue; }
            for (int k = i + 1; k < N && k <= i + s; k++) {
                if (d < height[k]) { continue; }
                reach[k] = min(j, reach[k]);
            }
        }
    }
    cout << reach[N - 1];
}