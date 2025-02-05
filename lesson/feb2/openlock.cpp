#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string target; cin >> target;
    int N; cin >> N;
    map<string, int> dist;
    for (int i = 0; i < N; i++) {
        string x; cin >> x;
        dist[x] = -1;
    }
    dist["0000"] = 0;
    queue<string> q;
    q.push("0000");
    while (!q.empty()) {
        string u = q.front(); q.pop();
        int d = dist[u];
        for (int i = 0; i < 4; i++) {
            char nc = u[i] + 1;
            if (u[i] == '9') { nc = '0'; }
            bool works = true;
            swap(nc, u[i]);
            if (!dist.count(u)) {
                dist[u] = d + 1;
                q.push(u);
            }
            swap(nc, u[i]);
            nc = u[i] - 1;
            if (u[i] == '0') { nc = '9'; }
            swap(nc, u[i]);
            if (!dist.count(u)) {
                dist[u] = d + 1;
                q.push(u);
            }
            swap(nc, u[i]);
        }
    }
    if (dist.count(target)) { cout << dist[target] << "\n"; }
    else { cout << -1 << "\n"; }
}