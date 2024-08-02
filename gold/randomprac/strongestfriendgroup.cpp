#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> degree;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N);
    degree.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a); // wait
        degree[a]++;
        degree[b]++;
    }
    vector<bool> ingroup(N, true);
    map<int, vector<int>> group;

    for (int i = 0; i < N; i++) {
        group[graph[i].size()].push_back(i);
    }
    while (!group.empty()) {  //we need to keep track of
        
    }

}