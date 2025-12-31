#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for (auto i=a; i<(b); i++)

vt<vt<int>> T;
vt<int> par;
vt<int> in, subsize;
vt<int> depth;
int euler = 0;
int dfs(int u) {
    in[u] = euler++;
    for (int v : T[u]) {
        if (v == par[u]) { continue; }
        par[v] = u;
        depth[v] = depth[u] + 1;
        subsize[u] += dfs(v);
    }
    return subsize[u];
}
bool is_anc(int u, int v) {
    return in[u] <= in[v] && in[v] + subsize[v] <= in[u] + subsize[u];
}

const int maxj = 20;
vt<ii<maxj>> jump;
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    rep(b, 0, 20) {
        if (depth[u] - depth[v] >> b & 1) {
            u = jump[u][b];
        }
    }
    if (u == v) {
        return u;
    }
    for (int b = 20 - 1; b > -1; b--) {
        if (jump[u][b] != jump[v][b]) {
            u = jump[u][b], v = jump[v][b];
        }
    }
    return par[u];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    T.resize(N), par.resize(N);
    in.resize(N), subsize.resize(N, 1);
    depth.resize(N);
    
    rep(i, 0, N - 1) {
        int u, v; cin >> u >> v;
        T[u].add(v);
        T[v].add(u);
    }
    dfs(0);
    jump = vt<ii<maxj>>(N, ii<maxj>{});
    rep(i, 0, N) {
        jump[i][0] = par[i];
    }
    rep(j, 1, maxj) {
        rep(i, 0, N) {
            jump[i][j] = jump[jump[i][j-1]][j-1];
        }
    }

    int U = 0, V = 0;
    vt<ii<2>> save;
    rep(i, 1, N) {
        //try with U
        if (is_anc(U, i)) {
            U = i;
            save.add({ U, V });
            continue;
        }   else if (is_anc(i, U)) {
            save.add({ U, V });
            continue;
        }   else if (is_anc(V, i)) {
            V = i;
            save.add({ U, V });
            continue;
        }   else if (is_anc(i, V )) {
            save.add({ U, V });
            continue;
        }
        break;
    }


    int ans = 1;
    int subsize_u = 0;
    int sum_up = 1;
    for (int v : T[0]) {
        ans += sum_up * (subsize[v]);
        sum_up += subsize[v];
        if (is_anc(v, U)) {
            subsize_u = subsize[v];
        }
    }
    rep(i, 0, size(save)) {
        auto [u, v] = save[i];
        if (lca(u, v) != 0) { //fairly certain its unnecessary but since i already wrote it why not
            break;
        }
        if (is_anc(v, u)) {
            ans += (N - subsize_u) * subsize[u];
        }   else {
            ans += subsize[u] * subsize[v];
        }
    }
    cout << ans << "\n";


}