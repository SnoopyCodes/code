#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    set<arr<int, 2>> e;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        if (u > v) { swap(u, v); }
        if (u == v) { ans++; continue; }
        if (e.count({u, v})) { ans++; }
        e.insert({u, v});
    }
    cout << ans << "\n";
}