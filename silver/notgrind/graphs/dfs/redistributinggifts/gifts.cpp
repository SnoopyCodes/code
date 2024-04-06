#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> wish;
vector<vector<bool>> reaches;
void dfs(int src, int cur) {
    if (reaches[src][cur]) { return; }
    reaches[src][cur] = true;
    for (int i : wish[cur]) {
        dfs(src, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    wish.resize(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> wish[i][j];
            wish[i][j]--;
        }
        while (wish[i].back() != i) { wish[i].pop_back(); }
    }
    reaches.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        dfs(i, i);
    }
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (!reaches[wish[i][j]][i]) {
            j++;
        }
        cout << wish[i][j]+1 << "\n";
    }
}