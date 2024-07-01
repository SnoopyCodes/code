#include <bits/stdc++.h>

using namespace std;
vector<int> nxt;
vector<int> visited;
vector<int> ans;
vector<bool> in_stack;
int t = 1;
bool found = false;
int g = -1;
int dfs(int v) {
    if (visited[v]) {
        if (in_stack[v]) {
            g = v;
            return t - visited[v];
        }
        found = true;
        return ans[v];
    }
    in_stack[v] = true;
    visited[v] = t++;
    ans[v] = dfs(nxt[v]) + found;
    if (v == g) { found = true; }
    in_stack[v] = false;
    return ans[v];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    nxt.resize(N);
    ans.resize(N);
    visited.resize(N);
    in_stack.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nxt[i];
        nxt[i]--;
    }
    //obviously we need to visit every connected component
    for (int i = 0; i < N; i++) {
        found = false;
        if (!visited[i]) { dfs(i); }
        cout << ans[i];
        if (i != N - 1) { cout << " "; }
    }
    cout << "\n";
}