#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

int qp(int x, int p = MOD - 2) { return p ? (p & 1 ? x : 1) * qp(x * x % MOD, p / 2) % MOD : 1; }

vt<vt<int>> T;
vt<int> fac, ifac, subsz;

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % MOD * ifac[n - r] % MOD; }

void prec(int n) {
	fac.resize(n + 1), ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}

int dfs(int u, int p) {
    int res = 1;
    for (int v : T[u]) {
        if (v == p) { continue; }
        (res *= dfs(v, u)) %= MOD;
        subsz[u] += subsz[v];
    }
    int cnt = subsz[u] - 1;
    for (int v : T[u]) {
        if (v == p) { continue; }
        (res *= choose(cnt, subsz[v])) %= MOD;
        cnt -= subsz[v];
    }
    return res;
}



void solve() {
    int N; cin >> N;
    if (N > 2000) {
        return;
    }
    T = vt<vt<int>>(N);
    fac = vt<int>(N + 1, 1);
    rep(i, 0, N - 1) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }
    rep(i, 1, N + 1) fac[i] = fac[i - 1] * i % MOD;
    int ans = 0;
    rep(i, 0, N) {
        subsz = vt<int>(N, 1);
        (ans += dfs(i, -1)) %= MOD;
    }
    cout << ans * qp(fac[N-1] * fac[N] % MOD) % MOD << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(1e6);
    int T; cin >> T; while (T --> 0) solve();
}
/*
we have an unrooted tree.
how many rooted trees, generated at random, correspond to this one?
isn't this freaking tree isomorphism ???????????????????

we know its somehow tree dp
for each u, virtually "reorder" the subtrees 1 through however many

for a certain tree structure, if it is isomorphic to our tree, then there's only 1 way to label it
to our tree.
like...
okay we have u and subtrees a, b, c.
the total subtree size not including u is k. we want the # of ways to label subtree excluding u
and rearrange it such that it is ismorphic to u and each p_v < v for all v in subtree?

wtf we need better reduction bro
we have tree!

we do root stuff.
i think solving for each root is a good idea.
yes. now we have to solve the problem above i think

simplify. we know ways to form stuff for each child v's subtree.
that "isomorphic" is weird. arrange them from smallest to largest.
interesting its just choose some stuff and go i believe.

then at this point we can go for N^2. do that and then ac 1 and 2 and maybe we make it maybe not.

how do we reroot? 
*/