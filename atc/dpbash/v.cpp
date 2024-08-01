#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<int>> tree;
vector<ll> subtree; //in the subtree when rooted from 0
int N, M;
void subtrees(int v, int from) {
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    tree.resize(N);
    subtree.resize(N, 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    subtrees(0, -1);
    //slowly..
    //they do not want you to calculate eulers totient functoin
    //calculate i think in subtree
    //for each child it contributes
    //1 (child white) + child (if child black)
    //coloring children sounds wrong
    //

}