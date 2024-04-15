#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> tree;
//what to do now?
//i think we euler tour as before
//what does this grant us?
//wait maybe we store for each node its like furthest down children??
//gtg do mastering physics cya
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    tree.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        //maybe add the other?
        tree[b].push_back(a);
    }

}