#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

/*
tree split middle thing yes ok
me when i have to write code
*/

void dfs_depth(int u, int p, vt<vt<int>> &T, vt<int> &d) {
    for (int v : T[u]) {
        if (v == p) { continue; }
        d[v] = d[u] + 1;
        dfs_depth(v, u, T, d);
    }
}

bool dfs(int u, int p, vt<vt<int>> &T, int d, set<int> &s, int td) {
    if (size(T[u]) == 1 && td == d) {
        s.insert(d);
        return true;
    }
    int amt = 0;
    for (int v : T[u]) {
        if (v == p) { continue; }
        amt += dfs(v, u, T, d + 1, s, td);
    }
    if (amt > 1) {
        s.insert(d);
    }
    return amt;
}

void solve() {
    int N; cin >> N;
    vt<vt<int>> T(N);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    vt<int> d_z(N);
    dfs_depth(0, -1, T, d_z);
    int a = ranges::max_element(d_z) - begin(d_z);
    d_z[a] = 0;
    dfs_depth(a, -1, T, d_z);
    int dia = *ranges::max_element(d_z);
    int b = ranges::max_element(d_z) - begin(d_z);
    vt<int> d_b(N);
    dfs_depth(b, -1, T, d_b);
    b = a = -1;
    for (int i = 0; i < N; i++) {
        if (d_z[i] == dia / 2 && d_z[i] + d_b[i] == dia) {
            a = i;
        }   else if (d_z[i] == dia / 2 + 1 && d_z[i] + d_b[i] == dia) {
            b = i;
        }
    }
    //a and b are 2 roots.
    //now dfs a and b, mark leaves, return depths.
    set<int> as, bs;
    // cout<< a << " " << b << endl;
    dfs(a, b, T, 0, as, dia / 2);
    dfs(b, a, T, 0, bs, dia / 2);
    set<int> ys;
    for (int x : as) {
        for (int y : bs) {
            ys.insert(x + y + 1);
        }
    }
    cout << ys.size() << " ";
    for (int x : ys) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}