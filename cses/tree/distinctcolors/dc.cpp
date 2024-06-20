#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
vector<int> colors;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    tree.resize(N); colors.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    //okay so uh
    //is this even a segtree problem
    //I feel like it is not
    //uh
    //wait we should re implement like company queries 2 or something
}