#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> paths;
vector<int> visited;
vector<int> zero;
vector<int> en;
pair<int, int> test;  //dist from starting and ending
int bs0(int x) {  //bs for largest less than x
    int s = 0, e = zero.size();
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (zero[m] > x) { e = m; }
        else { s = m; }
    }
    int dist = abs(x - zero[s]);
    if (x == 9)
    if (s != zero.size() - 1) {
        dist = min(dist, zero[s+1] - x);
    }
    return dist;
}
int bsN(int x) {
    int s = 0, e = en.size();
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (en[m] > x) { e = m; }
        else { s = m; }
    }
    int dist = abs(x - en[s]);
    if (s != en.size() - 1) {
        dist = min(dist, en[s+1] - x);
    }
    return dist;
}
void dfs(int i, int col) {
    if (visited[i]) { return; }
    visited[i] = col;
    if (col == 1) { zero.push_back(i); }
    else if (col == visited.size()) {  //find mindist from 0
        en.push_back(i);
        test.first = min(test.first, bs0(i));
    }
    else {  //find dists from 0 and end
        test.first = min(test.first, bs0(i));
        test.second = min(test.second, bsN(i));
    }
    for (int x : paths[i]) {
        dfs(x, col);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M; cin >> N >> M;
        zero.clear(); en.clear();
        paths.clear(); paths.resize(N);
        visited.clear(); visited.resize(N);
        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }
        ll best = INT_MAX;
        dfs(0, 1);
        test.first = INT_MAX; test.second = 0;
        if (visited[N-1]) { cout << "0" << "\n"; continue; }  //alr connected
        sort(zero.begin(), zero.end());
        dfs(N-1, N);
        best = min(best, (ll) test.first * test.first + test.second * test.second);
        sort(en.begin(), en.end());
        for (int i = 1; i < N - 1; i++) {
            if (!visited[i]) {  //color all cc
                test.first = INT_MAX; test.second = INT_MAX;
                dfs(i, 100);
                best = min(best, (ll) test.first * test.first + test.second * test.second);
            }
        }
        cout << best << "\n";
    }
}