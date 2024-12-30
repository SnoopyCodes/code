#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<int> weight, talent;
int N, W;

bool valid(int X) {
    //X <= talent / weight
    //weight * X <= talent
    //weight * X - talent <= 0
    //thus run a min knapsack on this function
    //if we can form a weight >= W with nonpositive sum
    vector<long> least(W + 1, 1e9);
    least[0] = 0;
    for (int i = 0; i < N; i++) {
        long val = (long) X * weight[i] - talent[i] * 1000;
        for (int j = W; j > -1; j--) {
            if (least[j] == 1e9) { continue; }
            least[min(W, weight[i] + j)] = min(least[min(W, weight[i] + j)], least[j] + val);
        }
    }

    return least[W] <= 0;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin >> N >> W;
    weight.resize(N), talent.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> talent[i];
    }
    int s = 0, e = 1e9;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (valid(m)) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}