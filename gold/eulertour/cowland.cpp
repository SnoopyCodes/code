#include <bits/stdc++.h>

using namespace std;
vector<int> happies;
vector<vector<int>> routing;
vector<int> start;
vector<int> stop;
int n, euler = 0;
void dfs(int v, int from) {
    start[v] = euler;
    euler++;
    for (int x : routing[v]) {
        if (x == from) { continue; }
        dfs(x, v);
    }
    stop[v] = euler;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int q; cin >> n >> q;
    happies.resize(n);
    routing.resize(n);
    start.resize(n);
    stop.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> happies[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        routing[a].push_back(b);
        routing[b].push_back(a);
    }
    //isnt this basic xor'ing
    //probably lets impl

}