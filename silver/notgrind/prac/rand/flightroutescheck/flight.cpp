#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<int>> destinations;
vector<int> visited;
vector<int> visited2;
vector<int> path;
bool dfs(int i) {
    if (i == 0) { return true; }
    if (i == -1) { i++; }
    if (visited[i]) { return false; }
    visited[i] = true;
    for (int x : destinations[i]) {
        if (dfs(x)) { path[i] = true; }
    }
    return path[i];
}
void dfs2(int i) {
    if (visited2[i]) { return; }
    visited2[i] = true;
    for (int x : destinations[i]) {
        dfs2(x);
        if (path[x]) { path[i] = true; }
    }
}
//all the cities need to be able to reach 0...
//how do we check for this?
//let each the checks be reaching 0
//
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("test.txt", "r", stdin);
    int n, m;cin >> n >> m;
    destinations.resize(n);
    visited.resize(n);
    visited2.resize(n);
    path.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        destinations[a].push_back(b);
    }
    dfs(-1);
    dfs2(0);
    for (int i = 0; i < n; i++) {
        for (int j : destinations[i]) {
            if (path[j]) { path[i] = true; }
        }
    }
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            cout << "NO" << "\n";
            cout << 1 << " " << i+1 << "\n"; return 0;
        }   else if (!path[i]) {
            cout << "NO" << "\n";
            cout << i+1 << " " << 1 << "\n"; return 0;
        }
    }
    cout << "YES";
    //if you can travel from a to b, you can travel to any city b can travel to.
    //so if dfs on each one covers it works?
    //uhhh lets see
    //wait if i can travel from any city to any other city
    //it follows that i must be able to travel to myself via another city
    //therefore if 1 dfs covers all, we good.
}