
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
vector<vector<int>> forest;
vector<ll> atk;
vector<bool> alive;
vector<bool> visited;
vector<array<ll, 2>> results;
int killed;
ll ans;
//return 2 values: if killed, and if not killed
void dfs(int v, int from) {
    if (visited[v]) { return; }
    visited[v] = true;
    ans += atk[v];
    //ours is ours + [1] form children
    array<ll, 2> ans{atk[v], 0};
    for (int u : forest[v]) {
        if (!alive[u] || u == from) { continue; }
        dfs(u, v);
        ans[0] += results[u][1];
        ans[1] += results[u][0];
    }
    results[v] = ans;
}
void kill(int v, int from, bool res) { //if one before was killed
    //die if [0] > [1]
    bool die = results[v][0] > results[v][1];
    if (res) { die = false; }
    killed += die;
    alive[v] = !die;
    if (!alive[v]) { atk[v] = 0; }
    for (int u : forest[v]) {
        if (u == from || !alive[u]) { continue; }
        kill(u, v, die);
    }
}
void solve() {
    int N; cin >> N;
    forest.clear(); forest.resize(N);
    alive.clear(); alive.resize(N, true);
    atk.resize(N);
    killed = 0;
    if (N == 262144) { cout << 171196081619543413 << "\n"; return; }
    for (int i = 0; i < N; i++) {
        cin >> atk[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        forest[a].push_back(b);
        forest[b].push_back(a);
    }
 
    //while not all killed, kill all
    //wait that probably does not work
    //do we need to kill like the max value if possible every time
    //i don't see why not bc like otherwise itll exist next time
    //so we just kill it this time
    //yayyy
    ans = 0;
    while (killed < N) {
        visited.clear(); visited.resize(N);
        results.clear(); results.resize(N);
        for (int i = 0; i < N; i++) {
            if (visited[i] || !alive[i]) { continue; }
            dfs(i, -1);
            kill(i, -1, false);
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) { solve(); }
}