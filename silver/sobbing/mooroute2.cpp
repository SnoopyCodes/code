#include <bits/stdc++.h>

using namespace std;
vector<vector<array<int, 3>>> flights;
vector<int> arrive;
vector<int> lay;
void dfs(int u, int t) {
    int old = arrive[u];
    arrive[u] = t;
    int s = -1, e = flights[u].size();
    while (s + 1 < e) {  //find first flight leave >= t
        int m = (s + e) / 2;
        if (flights[u][m][0] < t + lay[u]) { s = m; }
        else { e = m; }
    }
    while (e < flights[u].size() && flights[u][e][0] < old + lay[u]) {
        if (flights[u][e][2] < arrive[flights[u][e][1]]) {
            dfs(flights[u][e][1], flights[u][e][2]);
        }
        e++;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    flights.resize(N);
    arrive.resize(N, 1e9 + 1);
    lay.resize(N);
    for (int i = 0; i < M; i++) {
        int p1, t1, p2, t2; cin >> p1 >> t1 >> p2 >> t2; p1--; p2--;
        flights[p1].push_back({t1, p2, t2});
    }
    for (int i = 0; i < N; i++) {
        cin >> lay[i];
        sort(flights[i].begin(), flights[i].end());
    }
    dfs(0, -lay[0]);
    arrive[0] = 0;
    // cout << "\n";
    for (int i = 0; i < N; i++) {
        if (arrive[i] == 1e9 + 1) { cout << -1 << "\n"; }
        else { cout << arrive[i] << "\n"; }
    }
}