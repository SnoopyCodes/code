#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout;
#define long long long

vector<int> charge, sub;
vector<vector<array<int, 2>>> T;
long cost = 0;
void dfs(int u, int p) {  //energy cost, total sum.
    //we have to decide whether to send up or down charge
    for (auto [v, w] : T[u]) {
        if (v == p) { continue; }
        dfs(v, u);
        sub[u] += sub[v];
        cost += (long) abs(sub[v]) * w;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //let dp[i] be min energy to do thing yes
    //screw it we ball
    charge.resize(N), T.resize(N), sub.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> charge[i];
        sub[i] = charge[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        T[u].push_back({ v, w });
        T[v].push_back({ u, w });
    }
    dfs(0, -1);
    cout << cost << "\n";
}