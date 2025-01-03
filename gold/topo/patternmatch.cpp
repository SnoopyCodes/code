#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //hopefully is fun
    //this looks really fun actually i like it

    //misread, goddamn it
    //what this does is it places stuff in an order such that for each constraint
    //the first string it matches is position i
    int N, M, K; cin >> N >> M >> K;
    vector<string> P(N);  //patterns- nodes
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
        //edge to all that match this one
        for (int mask = 0; mask < 1 << K; mask++) {
            string match = s;
            for (int b = 0; b < 1 << K; b++) {
                if (mask & 1 << b) { match[b] = '_'; }
            }
            if (m.count(match)) {
                int idx = m[match];
                cout << idx << " " << j << "\n";
                constraints[j].push_back(idx);
                in[idx]++;
            }
        }
    }
    vector<int> order;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) { q.push(i); }
        cout << in[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int x : constraints[i]) {
            in[x]--;
            if (in[x] == 0) { q.push(x); }
        }
        if (q.empty()) { cout << "NO" << "\n"; return 0; }
        int u = q.front();
        cout << u << "\n";
        q.pop();
        order.push_back(u);
    }
    cout << "YES" << "\n";
    for (int i = 0; i < N; i++) {
        cout << order[i] + 1 << " \n"[i == N - 1];
    }

}