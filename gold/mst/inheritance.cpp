#include <bits/stdc++.h>
//dynamic union find!
//implementation as below- i believe the constraint on N on this problem can be raised to N = 2e5 :P
//pretty cool trick, but tle's with standard map. 333 ms
using namespace std;
using ll = long long;
struct dynaUF {
    unordered_map<int, int> dsu;
    int find(int u) {
        if (!dsu.count(u)) { return u; }
        dsu[u] = find(dsu[u]);
        return dsu[u];
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (rand() % 2) {
            dsu[v] = u;
        }   else {
            dsu[u] = v;
        }
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    vector<int> ans(M, -1);
    vector<array<int, 4>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--; edges[i][2]--;
        edges[i][3] = i;
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    vector<dynaUF> children(K);
    for (int i = 0; i < M; i++) {
        int u = edges[i][1];
        int v = edges[i][2];
        int edge = edges[i][3];
        //find the first child for which these two aren't connected
        int s = -1, e = K;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (children[m].find(u) == children[m].find(v)) {
                s = m;
            }   else {
                e = m;
            }
        }
        if (e != K) {
            children[e].merge(u, v);
            ans[edge] = e;
        }
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] + 1 << "\n";
    }
}