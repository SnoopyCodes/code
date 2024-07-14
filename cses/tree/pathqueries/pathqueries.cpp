#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int v, i, s, e;  //value, start, end
    ll sum;
    vector<int> adj;
};
vector<Node> nodes;
vector<int> order;
int euler = 0;

void dfs(int v, int from, ll sum) {
    order[euler] = v;
    nodes[v].s = euler;
    nodes[v].sum = sum + nodes[v].v;
    euler++;
    for (int x : nodes[v].adj) {
        if (x == from) { continue; }
        dfs(x, v, nodes[v].sum);
    }
    nodes[v].e = euler;
}
vector<ll> seg;
int N;
void init() {
    //the way a difference array works is that if we want the ith element
    //we sum from 0 to i to get it i think
    //so its 1-indexed
    //no the first value is 0
    //why isnt it 0 indexed
    seg[N] = nodes[order[0]].sum;
    for (int i = 1; i < N; i++) {
        seg[i + N] = nodes[order[i]].sum - nodes[order[i-1]].sum;
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[2 * i + 1] + seg[2 * i];
    }
}
ll query(int v) {
    ll ans = 0;
    for (int l = N, r = nodes[v].i + N + 1; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            ans += seg[l++];
        }
        if (r & 1) {
            ans += seg[--r];
        }
    }
    return ans;
}
void update(int v, int val) {
    int l = nodes[v].s, r = nodes[v].e;  //okay its out of bounds bruh but it shouldnt matter
    bool over = r == N;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        seg[l] += val;
        if (!over)
        seg[r] -= val;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    nodes.resize(N);
    order.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nodes[i].v;
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        nodes[u].adj.push_back(v);
        nodes[v].adj.push_back(u);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < N; i++) {
        nodes[order[i]].i = i;
    }
    seg.resize(2 * N);
    init();
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int v, val; cin >> v >> val; v--;
            
            update(v, val - nodes[v].v);
            nodes[v].v = val;
        }   else {
            int v; cin >> v; v--;
            cout << query(v) << "\n";
        }
    }
}