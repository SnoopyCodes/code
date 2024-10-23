#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    int N, D; cin >> N >> D;
    vector<array<int, 2>> pies(2 * N);
    vector<int> dist(2 * N, -1);
    set<array<int, 2>> ev;
    set<array<int, 2>> bv;
    queue<int> q;
    for (int i = 0; i < 2 * N; i++) {
        cin >> pies[i][0] >> pies[i][1];
    }

    for (int i = 0; i < N; i++) {
        if (pies[i][1] == 0) {
            dist[i] = 1;
            q.push(i);
        }   else {
            ev.insert({pies[i][1], i});
        }
        if (pies[N + i][0] == 0) {
            dist[N + i] = 1;
            q.push(N + i);
        }   else {
            bv.insert({pies[N + i][0], N + i});
        }
    }

    while (!q.empty()) {
        int pie = q.front();
        q.pop();
        if (pie >= N) {
            auto it = ev.lower_bound({pies[pie][1] - D, -1});
            while (it != ev.end() && (*it)[0] <= pies[pie][1]) {
                int p = (*it)[1];
                dist[p] = dist[pie] + 1;
                q.push(p);
                it = ev.erase(it);
            }
        }   else {
            auto it = bv.lower_bound({pies[pie][0] - D, -1});
            while (it != bv.end() && (*it)[0] <= pies[pie][0]) {
                int p = (*it)[1];
                dist[p] = dist[pie] + 1;
                q.push(p);
                it = bv.erase(it);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dist[i] << "\n";
    }
}