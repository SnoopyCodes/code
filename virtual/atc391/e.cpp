#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    int len = (int) pow(3, N);
    vec<vec<int>> layer(N + 1);
    vec<vec<int>> change(N + 1);
    change[0].resize(len, 1);
    for (int i = 0; i < len; i++) {
        char c; cin >> c;
        layer[0].push_back(c == '1');
    }
    auto cnt = [&](int i, int j) {
        return (layer[i-1][j*3]+layer[i-1][j*3+1]+layer[i-1][j*3+2]);
    };
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < layer[i-1].size() / 3; j++) {
            layer[i].push_back(cnt(i, j) > 1);
        }
        change[i].rsz(layer[i].size());
        for (int j = 0; j < change[i].size(); j++) {
            //find minimum to change
            vec<int> costs;
            for (int k = j * 3; k < j * 3 + 3; k++) {
                if (layer[i-1][k] != layer[i][j]) { continue; }
                costs.push_back(change[i-1][k]);
            }
            sort(costs.begin(), costs.end());
            int total = 0;
            for (int k = 0; k < costs.size() - 1; k++) {
                total += costs[k];
            }
            change[i][j] = total;
        }
    }
    cout << change[N][0] << "\n";
}