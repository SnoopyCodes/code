#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> in_time;
vector<int> low_euler;
vector<int> in_kingdom;
int euler = 0;
int kings = 0;
vector<vector<int>> kingdoms;
stack<int> st;
void dfs(int v) {
    in_time[v] = euler;
    low_euler[v] = euler;
    euler++;
    st.push(v);
    for (int adj : graph[v]) {
        if (in_time[adj] == -1) { dfs(adj); }
        if (in_kingdom[adj] == -1) { low_euler[v] = min(low_euler[v], low_euler[adj]); }
    }
    if (low_euler[v] == in_time[v]) {
        kingdoms.push_back({});
        int u = -1;
        while (u != v) {
            u = st.top();
            st.pop();
            kingdoms[kings].push_back(u);
            in_kingdom[u] = kings;
        }
        kings++;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N);
    in_time.resize(N, -1);
    in_kingdom.resize(N, -1);
    low_euler.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        if (in_time[i] == -1) { dfs(i); }
    }
    cout << kings << "\n";
    for (int i = 0; i < N; i++) {
        cout << in_kingdom[i]+1 << " \n"[i == N - 1];
    }
}