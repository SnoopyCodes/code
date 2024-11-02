#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //trivially connect stuff, bruh
    //here is what i misread as (and a slightly more confusing problem)
    //for each constraint string s, int j, find an ordering
    //such that string j in the final ordering is the first one that it matches
    int N, M, K; cin >> N >> M >> K;
    vector<string> P(N);  //patterns- nodes. you only need the map, but i still have strings here
    vector<int> in(N);
    map<string, int> m;
    vector<vector<int>> constraints(N);  //edges from indexes (here) to nodes
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        m[P[i]] = i;
    }
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        int j; cin >> j; j--;
        for (int k = 0; k < K; k++) {
            if (s[k] != P[j][k] && P[j][k] != '_') { cout << "NO" << "\n"; return 0; }
        }
        for (int mask = 0; mask < 1 << K; mask++) {
            string match = s;
            for (int b = 0; b < 1 << K; b++) {
                if (mask & 1 << b) { match[b] = '_'; }
            }
            if (m.count(match)) {
                if (match == P[j]) { continue; }
                int idx = m[match];
                constraints[j].push_back(idx);
                in[idx]++;
            }
        }
    }
    queue<int> q;
    vector<int> order;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : constraints[u]) {
            in[v]--;
            if (in[v] == 0) { q.push(v); }
        }
    }
    if (order.size() == N) {
        cout << "YES" << "\n";
        for (int i = 0; i < N; i++) {
            cout << order[i] + 1 << " \n"[i == N - 1];
        }
    }   else {
        cout << "NO" << "\n";
    }
}