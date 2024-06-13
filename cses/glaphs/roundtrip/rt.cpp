#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> city;
vector<int> tin;
vector<int> last;
int t = 1;
bool found = false;
void dfs(int v, int from) {
    tin[v] = t;
    last[v] = from;
    t++;
    for (int x : city[v]) {
        if (!tin[x]) {
            dfs(x, v);
            t--;
        }   else if (tin[v] - tin[x] >= 2 && !found) {
            found = true;
            vector<int> path; path.push_back(x);
            while (v != x) {
                path.push_back(v);
                v = last[v];
            }
            cout << path.size() + 1 << endl;
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] + 1 << " ";
            }
            cout << x+1;
            cout << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    city.resize(N);
    tin.resize(N);
    last.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        if (!tin[i]) {
            dfs(i, -1);
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << "\n";
    }
    //essentially, find a cycle.
    //is this doable with dfs?
    //
}