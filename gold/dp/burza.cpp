#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    tree.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    //suppose we are on a straight branch
    //we want to be able to select a node for which all its neighbors are marked, and it itself is not marked
    //this is probably like proving that 
    //there is a bound or smth
    //we need to like choose some??
    //damn
    //we can obviously check if it is impossible
    //then, we want to 
    //this looks basically impossible look at it later trust
}