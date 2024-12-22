#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<int> dsu;
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return; }
    if (rand() % 2) { dsu[u] = v; }
    else { dsu[v] = u; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> len(N);
    dsu.resize(K);
    for (int i = 0; i < N; i++) {
        cin >> len[i];
    }
    for (int i = 0; i < K; i++) {
        dsu[i] = i;
    }
    //assign each farmer to its thing
    //then record times for every single farmer
    //give every farmer a time that it ends
    //we need to record for each farmer the times in which it appears
    //at a specific time, all the farmers at that time can appear in other places
    //only through this one
    //we can iterate through all intersection points, it doesn't have to be backwards
    //thus arbitrarily push times

    //why rte?
    //
    map<long, vector<int>> intersect;
    priority_queue<array<long, 2>> pq;
    for (int i = 0; i < K; i++) {
        pq.push({-len[i], i});
    }
    for (int i = K; i < N; i++) {
        auto [t, f] = pq.top(); pq.pop();
        intersect[t].push_back(f);
        pq.push({t - len[i], f});
    }
    int f = pq.top()[1];
    long t = pq.top()[0];
    while (!pq.empty()) {
        auto [tt, ff] = pq.top(); pq.pop();
        intersect[tt].push_back(ff);
    }
    cout << -t << "\n";
    for (auto [z, cur] : intersect) {
        bool in = false;
        for (int x : cur) {
            if (find(x) == find(f)) { in = true; break; }
        }
        if (in)
        for (int x : cur) {
            merge(x, f);
        }
    }
    for (int i = 0; i < K; i++) {
        cout << (find(i) == find(f));
    }
    cout << "\n";
}