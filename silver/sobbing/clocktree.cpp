#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> corridors;
vector<int> cur;
int sum1 = 0, sum2 = 0;
int in1 = 0, in2 = 0;

void dfs(int u, int par, bool t) {
    if (t) { sum2 += cur[u]; in2++; }
    else { sum1 += cur[u]; in1++; }
    for (int v : corridors[u]) {
        if (v == par) { continue; }
        dfs(v, u, !t);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    //this looks very tricky
    //we have a tree
    //we must end up on an 11
    //i think it is something about the leaves...
    //in each branch, we want to leave with all set to 12
    //it definitely has something to do with the leaves
    //this is just a bipartite thingy
    //when we walk from one place to another stuff happens
    //so: if difference is <= 1, then it is possible
    //otherwise not
    int N; cin >> N;
    corridors.resize(N);
    cur.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cur[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        corridors[u].push_back(v);
        corridors[v].push_back(u);
    }
    dfs(0, 0, 0);
    sum1 %= 12, sum2 %= 12;
    if (sum1 > sum2) { swap(sum1, sum2); swap(in1, in2); }
    if (sum1 == 0 && sum2 == 11) { sum1 = 12; swap(sum1, sum2); swap(in1, in2); }
    if (sum2 - sum1 > 1) { cout << 0 << "\n"; }
    else {
        if (sum1 > sum2) { cout << in1 << "\n"; }
        else if (sum2 > sum1) { cout << in2 << "\n"; }
        else { cout << N << "\n"; }
    }
}