#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> barns;
vector<int> a;
int dfs(int u, int from, int k) {  //path length through this node
    map<int, int> m;  //desperation
    for (int v : barns[u]) {
        if (v == from) { continue; }
        int res = dfs(v, u, k);
        if (k == 2) {
            a[v] = res;
        }
        res = (res + 1) % k;
        if (m[k - res]) { m[k - res]--; }
        else { m[res]++; }
    }
    int take = 0;

    for (auto p : m) {
        if (p.first == 0 || p.second == 0) { continue; }
        if (!take && p.second == 1) { take = p.first; }
        else { return INT_MIN / 2; }
    }
    return take;
    //this should not tle i think
    //we should probably just use multiset actually nvm
    //we need to pair up nodes so that they add to k


}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("deleg.in", "r", stdin);
    // freopen("deleg.out", "w", stdout);
    int N; cin >> N;
    barns.resize(N);
    a.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        barns[u].push_back(v);
        barns[v].push_back(u);
    }
    //so paths cannot come back obviously
    //maybe do N <= 1e3 first
    //oh
    //evey path of length x can be partitioned into path lengths of 
    //1 and length - 1
    //therefore it builds
    //i can also just iterate through divisors of N
    //then this probably works
    for (int i = 0; i < N - 1; i++) {
        if ((N - 1) % (i + 1) != 0) {
            cout << 0; 
            continue;
            }
        //now just find if we can split it into path lengths of exactly i + 1
        // cout << i + 1 << "\n";
        cout << (dfs(0, -1, i + 1) % (i + 1) == 0);
    }
    // for (int i = 0; i < N; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
}