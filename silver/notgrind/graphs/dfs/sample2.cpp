#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
vector<int> newroads;
vector<vector<int>> v;
int a;
void dfs(int x) {
    cout << "HI";
    a++;
    cout << a << "\n";
    if (visited[x]) { return; }
    visited[x] = true;
    for (int i : v[x]) { dfs(i); }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << "\n";
    visited.resize(n);
    v.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (i != 0) { c++; newroads.push_back(i+1); }
            dfs(i);
        }
    }
    cout << c << "\n";
    for (int i : newroads) { cout << "1 " << i << "\n"; }
}