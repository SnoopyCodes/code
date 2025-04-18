#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    unordered_map<string, int> dist;
    string start = "";
    for (int i = 0; i < 9; i++) {
        char c; cin >> c;
        start += c;
    }
    string end = "123456789";
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    while (!dist.count(end)) {
        string u = q.front(); q.pop();
        int d = dist[u];
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 2) { continue; }
            swap(u[i], u[i + 1]);
            if (!dist.count(u)) {
                dist[u] = d + 1;
                q.push(u);
            }
            swap(u[i], u[i + 1]);
        }
        for (int i = 0; i < 6; i++) {
            swap(u[i], u[i + 3]);
            if (!dist.count(u)) {
                dist[u] = d + 1;
                q.push(u);
            }
            swap(u[i], u[i + 3]);
        }
    }
    cout << dist[end] << "\n";
}