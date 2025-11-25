#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back

const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;

template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;

template<class T> using vt = vector<T>;
template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class... A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> { using vt<T>::vt; mt(const vt<T>& v) : vt<T>(v) {} };

int dfs(int u, int p, mt<int, 2> &G, vt<int> &in, int &euler, vt<bool> &is_art, vt<int> &par, vt<int> &depth, int d, vt<int> &out) {
    int low = in[u] = euler++, trav = 0;
    depth[u] = d;
    par[u] = p;
    bool is = false;
    for (int v : G[u]) {
        if (v == p) { continue; }
        if (in[v] == -1) {
            int res = dfs(v, u, G, in, euler, is_art, par, depth, d + 1, out);
            low = min(low, res);
            if (res >= in[u] && p != -1) { is = true; }
            trav++;
        }   else { low = min(low, in[v]); }
    }
    out[u] = euler;
    if (trav > 1 && p == -1 || is) { is_art[u] = true; }
    
    return low;
}

int kth_anc(int u, int k, mt<int, 2> &jump) {
    for (int i = 0; i < jump.size(); i++) {
        if (k & 1 << i) { u = jump[i][u]; }
    }
    return u;
}

int lca(int u, int v, mt<int, 2> &jump, vt<int> &depth) {
    if (depth[u] < depth[v]) { swap(u, v); }
    u = kth_anc(u, depth[u] - depth[v], jump);
    if (u == v) { return u; }
    for (int i = jump.size() - 1; i > -1; i--) {
        if (jump[i][u] != jump[i][v]) {
            u = jump[i][u], v = jump[i][v];
        }
    }
    return jump[0][u];
}

int is_anc(int u, int v, vt<int> &in, vt<int> &out) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    mt<int, 2> G(N);
    vt<bool> is_art(N);
    vt<int> in(N, -1);
    vt<int> par(N, -1);
    vt<int> depth(N, -1);
    vt<int> out(N, -1);

    while (M --> 0) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }
    int euler = 0;
    dfs(0, 0, G, in, euler, is_art, par, depth, 0, out);
    int LG = __lg(N - 1) + 1;
    mt<int, 2> jump(LG, N);
    for (int i = 0; i < N; i++) {
        jump[0][i] = par[i];
    }
    for (int i = 1; i < LG; i++) {
        for (int j = 0; j < N; j++) {
            jump[i][j] = jump[i-1][jump[i-1][j]];
        }
    }
    
    while (Q --> 0) {
        int u, v, w; cin >> u >> v >> w; u--; v--; w--;
        int anc = lca(u, v, jump, depth);
        bool on_u_to_root = lca(u, w, jump, depth) == w;
        bool on_v_to_root = lca(v, w, jump, depth) == w;
        cout << is_art[w] << "\n";
        if ((on_u_to_root || on_v_to_root) && depth[w] >= depth[anc] && is_art[w]) {
            cout << "NO" << "\n";
        }   else {
            cout << "YES" << "\n";
        }
    }
}