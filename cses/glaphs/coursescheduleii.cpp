#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> prereqs(N);
    vector<int> out(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        prereqs[b].push_back(a);
        out[a]++;
    }
    //sob
    //wait this was like toposort on radj and then reverse
    //we are essentially assigning the "index" starting from N - 1 to 0 decreasing
    //bruh this seems instinctively correct
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        if (!out[i]) { pq.push(i); }
    }

    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (int v : prereqs[u]) {
            out[v]--;
            if (out[v] == 0) { pq.push(v); }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}