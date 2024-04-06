#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<int>> paths;
vector<int> type;
vector<bool> visited;
void dfs(int i, int mark) {
    if (visited[i]) { return; }
    visited[i] = true;
    type[i] = mark;
    for (int x : paths[i]) {
        dfs(x, mark);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("8.in", "r", stdin);
    // freopen("8.out", "w", stdout);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M; cin >> N >> M;
        paths.clear(); visited.clear(); type.clear();
        paths.resize(N);
        visited.resize(N);
        type.resize(N);
        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }
        //find at most 4 points so that a to b and c to d is minimized and everything is connected
        //when should we use 2?
        //if there is a third connected component usable such that start to it and it to end is smaller than start to end
        //use "one" when optimal is just to connect start to finish; if > 1 dist split it into 2 as even as possible
        //first dfs the first one and the ending one.
        //then run more dfs on the rest; figure out distance of it from beginning cc to end cc
        //wait we can probably do that by running through it afterwards and keeping a pair of closest cc from left side
        //and then do that from teh right side
        //and then if we select that one we can easily find the cost of using it as a middle cc
        //easy?
        dfs(0, 0);
        dfs(N - 1, N - 1);
        if (type[N - 1] == 0) { cout << 0 << "\n"; continue; }  //if it is already connected
        for (int i = 1; i < N - 1; i++) {
            if (visited[i]) { continue; }
            dfs(i, i);
        }
        map<int, pair<int, int>> m; //each connected component type .first, .second.first is the closest distance to start cc;
        m.clear();
        pair<int, int> closest;     // .second.second is the closest to end cc
        closest.first = 0; closest.second = N - 1;
        int toend = INT_MAX;
        for (int i = 1; i < N; i++) {
            int cc = type[i];
            if (cc == 0) { closest.first = i; toend = min(toend, abs(i - closest.second)); continue; }
            else if (cc == N - 1) { closest.second = i; continue; }
            if (m[cc].first == 0) { m[i].first = INT_MAX; }
            if (m[cc].second == 0) { m[i].second = INT_MAX; }
            m[cc].first = min(m[cc].first, i - closest.first);
            m[cc].second = min(m[cc].second, abs(i - closest.second));
        }
        closest.first = 0; closest.second = N - 1;
        for (int i = N - 2; i >= 0; i--) {
            int cc = type[i];
            if (cc == 0) { closest.first = i; toend = min(toend, abs(i - closest.second)); continue; }
            else if (cc == N - 1) { closest.second = i; continue; }
            m[cc].first = min(m[cc].first, abs(-i + closest.first));
            m[cc].second = min(m[cc].second, -i + closest.second);
        }
        // for (auto& a : m) {
        //     cout << a.first << " " << a.second.first << " " << a.second.second << "\n";
        // }
        //hoping this O(N log N) works
        long long ans = LONG_LONG_MAX;
        for (auto& a : m) {
            ans = min(ans, (long long) a.second.first * a.second.first + (long long) a.second.second * a.second.second);
        }
        if (ans == LONG_LONG_MAX || toend == 1) { cout << 1 << "\n"; continue; }  //this means the map is blank; so the only 2 cc are start and end. additionally
        cout << ans << "\n";                        //distance between is one because there is no point
    }
}