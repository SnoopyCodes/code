#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string start; cin >> start;
    map<string, int> dist;
    string end = "123804765";
    queue<string> q; q.push(start);
    dist[start] = 0;
    vector<int> dr{1, -1, 0, 0}, dc{0, 0, 1, -1};
    while (!dist.count(end)) {
        string s = q.front(); q.pop();
        int p = s.find('0');
        int od = dist[s];
        int r = p / 3, c = p % 3;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nc < 0 || nr < 0 || nc == 3 || nr == 3) { continue; }
            swap(s[nr * 3 + nc], s[p]);
            if (dist.count(s)) { swap(s[nr * 3 + nc], s[p]); continue; }
            dist[s] = od + 1;
            q.push(s);
            swap(s[nr * 3 + nc], s[p]);
        }
    }
    cout << dist[end] << "\n";
    
}