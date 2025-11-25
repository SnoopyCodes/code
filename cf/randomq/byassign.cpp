#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 998244353;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int N, V;
mt<int> G;
vt<int> vals;

vector<int> in, path, in_cc;
mt<int> bcc;
int ncc = 0, euler = 0;

int dfs(int u, int p) {
    int low = in[u] = euler++, mult = 0;
    path.add(u);
    for (int v : G[u]) {
        if (v == p && !mult) { mult++; continue; }
        if (~in_cc[v]) { continue; }
        low = min(low, ~in[v] ? in[v] : dfs(v, u));
    }
    if (in[u] == low) {
        bcc.add({});
        while (in_cc[u] == -1) {
            bcc[ncc].add(path.back());
            in_cc[path.back()] = ncc; path.pop_back();
        }
        ncc++;
    }   else { in[u] = low; }
    return low;
}

bool bipartite(int u, int c, mt<int> &G, vt<int> &col) {
    col[u] = c;
    for (int v : G[u]) {
        if (col[v] != -1) {
            if (col[v] ^ c) { continue; }
            return false;
        }
        if (!bipartite(v, c ^ 1, G, col)) { return false; }
    }
    return true;
}

void solve() {
    ncc = euler = 0;
    int M; cin >> N >> M >> V;
    G = mt<int>(N);
    in = in_cc = vals = vt<int>(N, -1);
    for (int i = 0; i < N ;i++) {
        cin >> vals[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }

    dfs(0, -1);

    long ans = 1;
    
    auto g = mt<int>(N);
    auto col = vt<int>(N, -1);
    for (auto &cc : bcc) {
        set<int> diff;
        for (int u : cc) {
            diff.insert(vals[u]);
            for (int v : G[u]) {
                if (in_cc[u] == in_cc[v]) {
                    g[u].add(v);
                }
            }
        }
        if (*diff.begin() == -1) {
            diff.erase(-1);
        }

        if (size(diff) > 1 ||
                size(diff) == 1 && !bipartite(cc[0], 0, g, col) && (*diff.begin() != 0)) {
            ans = 0;
            break;
        }   else if (size(diff) == 0 && bipartite(cc[0], 0, g, col)) {
            (ans *= V) %= MOD;
        }
    }
    cout << ans << "\n";
    bcc.clear();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}