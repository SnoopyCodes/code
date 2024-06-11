#include <bits/stdc++.h>

using namespace std;
struct Query {
    int vid, k, i, ans;
};
bool compk(Query q1, Query q2) {
    return q1.k > q2.k;
}
bool compi(Query q1, Query q2) {
    return q1.i < q2.i;
}
struct Edge {
    int a, b, r;
};
bool compr (Edge e1, Edge e2) {
    return e1.r > e2.r;
}
vector<int> dsu;
vector<int> sizes;
int find(int v) {
    if (dsu[v] != v) {
        dsu[v] = find(dsu[v]);
    }
    return dsu[v];
}
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (rand() % 2) {
        dsu[v] = u;
        sizes[u] += sizes[v];
    }   else {
        dsu[u] = v;
        sizes[v] += sizes[u];
    }
}
int qsize(int v) {
    return sizes[find(v)];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int N, Q; cin >> N >> Q;
    dsu.resize(N);
    sizes.resize(N);
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
        sizes[i] = 1;
    }
    //i think here we take hte edges and sort them by relevancy, then take hte queries and sort htem by relevancy
    vector<Edge> edges(N - 1);
    vector<Query> queries(Q);
    for (int i = 0; i < N - 1; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].r;
        edges[i].a--; edges[i].b--;
    }
    sort(edges.begin(), edges.end(), compr);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].k >> queries[i].vid;
        queries[i].i = i;
        queries[i].vid--;
    }
    sort(queries.begin(), queries.end(), compk);
    int e = 0;
    for (int i = 0; i < Q; i++) {
        while (e < N - 1 && edges[e].r >= queries[i].k) {
            unite(edges[e].a, edges[e].b);
            e++;
        }
        queries[i].ans = qsize(queries[i].vid);
    }
    sort(queries.begin(), queries.end(), compi);
    for (int i = 0; i < Q; i++) {
        cout << queries[i].ans - 1 << "\n";
    }
}
