#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> forest(N);
    for (int i = 0; i < N; i++) {
        cin >> forest[i];
    }
    sort(forest.begin(), forest.end());
    vector<vector<int>> start(N);
    vector<vector<int>> end(N + 1);
    vector<int> lim(K);
    for (int i = 0; i < K; i++) {
        int l, r, t; cin >> l >> r >> t;
        l = lower_bound(forest.begin(), forest.end(), l) - forest.begin();
        r = upper_bound(forest.begin(), forest.end(), r) - forest.begin();
        //covers trees in [l,r)
        t = r - l - t;
        lim[i] = t;
        start[l].push_back(i);
        end[r].push_back(i);
    }
    int cur = 0;
    for (int i = 0; i < N; i++) {
        for (int x : end[i]) {
            cur = min(cur, lim[x]);
        }
        for (int x : start[i]) {
            lim[x] += cur;
        }
        cur++;
    }
    for (int x : end[N]) {
        cur = min(cur, lim[x]);
    }
    cout << cur << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T = 0;  cin >> T; while (T--) { solve(); }
}