#include <bits/stdc++.h>

using namespace std;

int reach[24][24];
bool in_first[24];
int N, M;
int cur = 0, ans = 0;

void recur(int u) {
    if (u == N) {
        ans = max(ans, cur);
        return;
    }
    in_first[u] = true;
    int sum = 0;
    int total = 0;
    for (int i = 0; i < u; i++) {
        if (!in_first[i]) { cur += reach[i][u]; sum += reach[i][u]; }
        total += reach[i][u];
    }
    recur(u + 1);
    cur -= sum;
    in_first[u] = false;
    cur += total - sum;
    recur(u + 1);
    cur -= total - sum;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        reach[u][v]++;
        reach[v][u]++;
    }
    recur(0);
    cout << ans << "\n";
}