#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> adj[100000];
vector<int> start(100000);  //shortest distance from start to any other node
vector<int> As(100000);
vector<int> Bs(100000);
int S, A, B;
void bfs(int s) {
    vector<bool> visited(100000);
    vector<int> parent(100000);
    queue<int> q;
    q.push(s);
    parent[s] = s;
    if (s == S) { start[s] = -1; }
    else if (s == A) { As[s] = -1; }
    else { Bs[s] = -1; }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (s == S) { start[i] = start[parent[i]]+1; }
        else if (s == A) { As[i] = As[parent[i]]+1; }
        else { Bs[i] = Bs[parent[i]]+1; }
        for (int x : adj[i]) {
            if (visited[x]) { continue; }
            q.push(x);
            visited[x] = true;
            parent[x] = i;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    cin >> S >> A >> B; S--; A--; B--;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(S);
    bfs(A);
    bfs(B);
    //iterate over start and find the nodes that satisfy being in between S and A, and in between S and B
    //note that the crucial poitn here was if a node's distance from S and a node's distance from A add up to distance between S and A,
    //that node MUST be between S and A
    int best = 0;
    for (int i = 0; i < N; i++) {
        cout << start[i] << " " << As[i] << " " << Bs[i] << "\n";
        if (start[A] == As[i] + start[i] && start[B] == Bs[i] + start[i]) { best = max(best, start[i]); }
    }
    cout << best << "\n";
}