#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> v;
int dfs(int x) {
    if (visited[x]) { return 0; }
    visited[x] = true;
    int count = 1;
    for (int i = 0; i < v[x].size(); i++) {
        count += dfs(i);
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << "HI";
    v.resize(n);
    for (int i = 0; i < m; i++) {
        int origin, destination;
        cin >> origin >> destination;
        v[origin-1].push_back(destination-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        visited.clear();
        visited.resize(n);
        int count = dfs(i);
        if (count < n - 1) {
            for (int j = 0; j < n; j++) {
                if (i == j) { continue; }
                if (!visited[j]) {
                    cout << "NO\n";
                    cout << i << " " << j;
                }
            }
        }
    }
    cout << "\n";
    cout << "YES";
}