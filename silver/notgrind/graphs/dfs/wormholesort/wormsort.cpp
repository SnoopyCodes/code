#include <bits/stdc++.h>

using namespace std;
struct Wormhole {
    int l1, l2, w;
    bool operator<(Wormhole wh) { return w < wh.w; }
};
vector<vector<Wormhole>> cows;
set<int> mustvisit;
vector<bool> visited;
int dfs(int x, int lim) {
    if (visited[x]) { return 0; }
    visited[x] = true;
    int count = 0;
    if (mustvisit.count(x)) { count++; }
    for (Wormhole wh : cows[x]) {
        if (wh.w >= lim) {
            if (x == wh.l1) { count += dfs(wh.l2, lim); }
            else { count += dfs(wh.l1, lim); }
        }
    }
    return count;
}
int main() {
    //the indexes that we need to visit are the indexes of our unsorted ones and the indexes of the ones out of place
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<int> widths(M);
    cows.resize(N);
    int dfsstart = -1;
    for (int i = 0; i < N; i++) {
        int cow;
        cin >> cow;
        cow--;
        if (cow != i) {
            mustvisit.insert(i);
            mustvisit.insert(cow);
            dfsstart = i;
        }
    }
    if (dfsstart == -1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < M; i++) {
        Wormhole wh;
        cin >> wh.l1 >> wh.l2 >> wh.w;
        wh.l1--; wh.l2--;
        widths[i] = wh.w;
        cows[wh.l1].push_back(wh);
        cows[wh.l2].push_back(wh);
    }
    sort(widths.begin(), widths.end());
    int s = 0, e = M;
    while (e - s > 1) {
        visited.clear(); visited.resize(N);
        int mid = (s + e) / 2;
        int search = dfs(dfsstart, widths[mid]);
        if (search == mustvisit.size()) { s = mid; }
        else { e = mid; }
    }
    cout << widths[s];
}