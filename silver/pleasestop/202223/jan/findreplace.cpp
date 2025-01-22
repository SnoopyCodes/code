#include <bits/stdc++.h>

using namespace std;

void solve() {
    string A; cin >> A;
    string B; cin >> B;
    int N = A.size();
    vector<int> to(52, -1); //this char goes to ?
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int c = A[i];
        if (c >= 97) { c -= 97; }
        else { c -= 65 - 26; }
        int ch = B[i];
        if (ch >= 97) { ch -= 97; }
        else { ch -= 65 - 26; }
        if (to[c] == -1 || to[c] == ch) { to[c] = ch; }
        else { ans = -1; }
    }
    if (ans == -1) { cout << ans << "\n"; return; }
    int notsame = 0;
    vector<bool> in(52);
    vector<vector<int>> radj(52);
    for (int i = 0; i < 52; i++) {
        if (to[i] == -1) { continue; }
        in[to[i]] = true;
        if (to[i] != i) { radj[to[i]].push_back(i); notsame++; }
        else { to[i] = -1; }
    }
    //all must be in use, and all must not equal themselves to be invalid?
    //wait suppose all are in end result
    //okay wait actual thinking time
    //if all 52 are in there and not equal to itself then it's over no matter 
    //find one condition where all teh conditions are valid
    //
    vector<bool> visited(52);
    for (int i = 0; i < 52; i++) {
        if (to[i] != -1) { continue; }
        queue<int> q; q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : radj[u]) {
                visited[v] = true;
                q.push(v);
                ans++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 52; i++) {
        cnt += in[i];
    }
    if (cnt == 52 && notsame != 0) { cout << -1 << "\n"; return; }
    vector<int> in_cyc(52, -1);
    vector<bool> done;
    for (int i = 0; i < 52; i++) {
        if (visited[i]) { continue; }
        int u = i;
        stack<int> path;
        while (!visited[u]) {
            visited[u] = true;
            path.push(u);
            u = to[u];
            ans++;
        }
        if (in_cyc[u] == -1) {
            ans++;
            while (in_cyc[u] == -1) {
                int v = path.top(); path.pop();
                in_cyc[v] = done.size();
            }
            ans -= path.size() != 0;
            done.push_back(path.size() != 0);
        }   else {
            while (!path.empty()) {
                int v = path.top(); path.pop();
                in_cyc[v] = in_cyc[u];
            }
            if (!done[in_cyc[u]]) {
                done[in_cyc[u]] = true;
                ans--;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}