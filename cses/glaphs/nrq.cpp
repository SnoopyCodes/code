#include <bits/stdc++.h>

using namespace std;
vector<int> dsu;
vector<unordered_set<int>> queries;  //vector
vector<int> days;
int find(int v) {
    if (dsu[v] == v) { return v; }
    dsu[v] = find(dsu[v]);
    return dsu[v];
}
void unite(int u, int v, int d) {
    u = find(u);
    v = find(v);
    if (u == v) { return; }
    if (rand() % 2) {
        dsu[u] = v;
    }   else {
        dsu[v] = u;
        swap(u, v);
    }
    //v is parent of u now, move u to v
    for (int x : queries[u]) {
        if (queries[v].find(x) == queries[v].end()) {
            queries[v].insert(x);
        }   else {
            days[x] = d;
            queries[v].erase(x);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    //we may utilize dsu on this for sure
    //but are we really to add queries to each cc
    //and then check each cc?
    //we can instead mark for each querie which cc it belongs to, then binary search on the first day 
    //for which they are the same?
    //naive approach is a scary O(MQ alpha(M)) where we check every day every query
    //storing for node where it goes...
    //this is the same as dragging it along isnt it?
    //honestly i bet this passes anyways like it should not but it probably will
    //actually i dont believe it
    //lmao
    //i think we can store for arrays whether or not we have a query in it
    //then we can check the query?
    //uhhh 
    //bruh
    //
    int N, M, Q; cin >> N >> M >> Q;
    vector<array<int, 2>> edges(M);
    queries.resize(N);
    dsu.resize(N);
    days.resize(Q, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        edges[i] = {a, b};
    }
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
    }
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        queries[a].insert(i);
        queries[b].insert(i);
        //figure out how to add it
    }
    for (int i = 0; i < M; i++) {
        unite(edges[i][0], edges[i][1], i+1);
    }
    for (int i = 0; i < 5; i++) {
        cout << days[i] << "\n";
    }
}