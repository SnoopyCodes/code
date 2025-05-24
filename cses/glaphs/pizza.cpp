#include <bits/stdc++.h>

using namespace std;

#define rsz resize
#define emb emplace_back
#define pob pop_back

vector<vector<int>> alt;
vector<int> in_cc, in, path;
int euler = 0, ncc = 0;
int dfs(int u) {  //return low
    int low = in[u] = euler++;
    path.emb(u);
    for (int v : alt[u]) {
        if (in[v] == -1) { low = min(low, dfs(v)); }
        else if (in_cc[v] == -1) { low = min(low, in[v]); }
    }
    if (in[u] != low) { return low; }
    while (in_cc[u] == -1) {
        int v = path.back(); path.pob();
        in_cc[v] = ncc;
    }
    ncc++;
    return low;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> M >> N;
    in_cc.rsz(2 * N, -1), in.rsz(2 * N, -1), alt.rsz(2 * N);
    for (int i = 0; i < M; i++) {
        char uc, vc; int u, v; cin >> uc >> u >> vc >> v;
        u = 2 * (u - 1), v = 2 * (v - 1);
        u += uc == '-';
        v += vc == '-';
        alt[u ^ 1].emb(v);
        alt[v ^ 1].emb(u);
    }
    for (int i = 0, u = 0; i < N; i++, u = 2 * i) {
        if (in[u] == -1) { dfs(u); }
        if (in[u ^ 1] == -1) { dfs(u ^ 1); }
        if (in_cc[u] == in_cc[u ^ 1]) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
    }
    for (int i = 0; i < 2 * N; i++) {
        in_cc[i] = ncc - in_cc[i] - 1;
    }
    for (int u = 0; u < 2 * N; u += 2) {
        cout << (in_cc[u] < in_cc[u ^ 1] ? "-" : "+") << " \n"[u == 2 * N - 2];
    }
}