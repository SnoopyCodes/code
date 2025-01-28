#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int V, N; cin >> V >> N;
    vector<long> best(V + 1, -1);
    best[0] = 0;
    for (int i = 0; i < N; i++) {
        int w, c; cin >> w >> c;
        for (int v = V; v > -1; v--) {
            if (w + v > V || best[v] == -1) { continue; }
            best[w + v] = max(best[v] + c, best[w + v]);
        }
    }
    cout << *max_element(best.begin(), best.end()) << "\n";
}