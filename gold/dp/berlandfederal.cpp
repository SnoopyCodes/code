#include <bits/stdc++.h>

using namespace std;
vector<vector<array<int, 2>>> towns;
vector<int> subtree;
int K;
//find subtree size
void findsize(int u, int from) {
    for (auto const&[v, e] : towns[u]) {
        if (v == from) { continue; }
        findsize(v, u);
        subtree[u] += subtree[v];
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N >> K;
    towns.resize(N);
    subtree.resize(N, 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        towns[u].push_back({v, i + 1});
        towns[v].push_back({u, i + 1});
    }
    
    //save the edges somewhere
    //but anyways uhh try to find 
    //wait we can
    //ok ill do this tomorrow believe me
    //if a node has subtree size >= k
    //use that node instead
    //wait but if its split theres hte troubel
    //dp[i][j] = 
}