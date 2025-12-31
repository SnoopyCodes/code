#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 998244353;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for (auto i=a; i<(b); i++)

vt<vt<int>> T;
vt<int> subsize, res;

int dfs(int u, int p) {
    for (int v : T[u]) {
        if (v == p) { continue; }
        subsize[u] += dfs(v, u);
    }
    if ((subsize[u] & 1) == 0 && u != 0) {
        res.add(subsize[u]);
        return 0;
    }
    return subsize[u];
}

long exp(long x, long p = MOD - 2) {
    return p ? (p & 1 ? x : 1) * exp(x * x % MOD, p / 2) % MOD : 1;
}

long dv(long a, long b) { return a * exp(b) % MOD; }

void solve() {
    int N; cin >> N;
    T.resize(N);
    subsize.resize(N, 1);
    rep(i, 0, N - 1) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }

    int init = dfs(0, -1);
    // cout << init << "\n";
    // rep(i, 0, size(res)) {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";
    /*
    now that we've decomposed the tree, we just need to link them in a path
    for all permutations with init as beginning we have
    a_1^2 * a_2^2 ... a_{k-1}^2 * a_k with a_k as the only term that is not squared.
    calculate init * (a_1 * a_2... a_k)^2
    then for each term divide and contribute
    */

    int k = size(res);
    long all_multiply = init;
    long arrange = 1;
    rep(i, 0, k) {
        if (i != k - 1) {
            (arrange *= i + 1) %= MOD;
        }
        (all_multiply *=  (long) res[i] * res[i] % MOD) %= MOD;
    }
    // cout << arrange << "\n";

    long ans = 0;
    rep(i, 0, k) {
        long factor = dv(all_multiply, res[i]);
        (ans += factor * arrange % MOD) %= MOD;
    }
    if (k == 0) {
        ans = 1;
    }

    cout << ans << "\n";

    T.clear();
    subsize.clear();
    res.clear();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}