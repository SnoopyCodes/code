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
    //exactly once per day, not twice
    //i think we will always do leaf nodes
    //also, if there is no loop already, adding a thing means that 
    //the original distance is shortened by number of nodes on the path
    //so from some root with depth d it is depth[node1] + depth[node2] + 1?
    //try to figure out just one first
    //abcdefghijklmnopqrstuvwxyz
    //k = 1 can surely be solved by a greedy algorithm of some sort
    //by enumerating the furthest leaf nodes from each branch
    //so thats some sort of dp, yeah
    //and we need to select 2 somehow
}