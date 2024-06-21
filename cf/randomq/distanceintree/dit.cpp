#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
vector<bool> visited;
long long ans;
int K;
vector<int> aux;  //size K
void dfs(int v, int d) {
    d++;
    visited[v] = true;
    vector<int> ours(aux.size());
    ours[0]++;
    for (int u : tree[v]) {
        if (visited[u]) { continue; }
        dfs(u, d+1);
        //the depth has been formed for htis one in aux
        for (int i = 0; i < K; i++) {
            //now be careful with how we match it up
            //we will work with our array
            //the aux is relative to the other
            //the other will have to have a dist of K - 1 if we have i = 0
            //
            ans += ours[i] * aux[K - 1 - i];
        }
        for (int i = 0; i < K - 1; i++) {
            ours[i+1] += aux[i];
        }
    }
    for (int i = 0; i < K; i++) {
        aux[i] = ours[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N >> K;
    tree.resize(N), visited.resize(N);
    aux.resize(K+1);
    //so the idea is to get the depths of all vertices, then combine them
    //yea we only need to store depths up to 500
    //uh O(NK) is fine
    //
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, 0);
    
    cout << ans << "\n";
}