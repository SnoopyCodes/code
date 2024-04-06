#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200000];
int dist1[200000];
int dist2[200000];
bool visited[200000];
void dfs(int v, int dist) {
    if (visited[v]) { return; }
    visited[v] = true;
    dist1[v] = dist;
    for (int i : adj[v]) {
        dfs(i, dist+1);
    }
    //lets see do we bfs??
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int e1 = 0, e2 = 0; //endpoints
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    for (int i = 1; i < n; i++) {
        if (dist1[i] > dist1[e1]) { e1 = i; }
    }
    memset(visited, false, 200000);
    dfs(e1, 0);
    for (int i = 1; i < n; i++) {
        if (dist1[i] > dist1[e2]) { e2 = i; }
    }
    for (int i = 0; i < n; i++) {
        dist2[i] = dist1[i];
    }
    memset(visited, false, 200000);
    dfs(e2, 0);
    for (int i = 0; i < n; i++) {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    //so we can find the endpoints of the diameters using double dfs
    //and then in the second dfs we should be figuring out all of the distances from 
    //endpoint to others
    //and one more dfs from the other endpoint
    //when printing out maximum dist to another node take max of them
}