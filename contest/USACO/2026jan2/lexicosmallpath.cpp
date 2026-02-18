#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

struct state {
    int infi = -2;
    ii<26> ct{};
    int last = 26;
    void upd(int x) {
        last = min(x, last);
        ct[x]++;
    }
};
bool cmp(const state &a,const state &b) {
    for (int i = 25; i > -1; i--) {
        if (a.infi == i && b.infi == i) {
            return false;
        }   else if (a.infi == i) {
            //if there's stuff after b, then a, otherwise b
            if (b.last >= i) return false;
            return true;
        }   else if (b.infi == i) {
            if (a.last >= i) return true;
            return false;
        }
        if (a.ct[i] != b.ct[i]) {
            return a.ct[i] < b.ct[i];
        }
    }
    return false;
}

void solve() {
    int N, M; cin >> N >> M;
    vt<vt<ii<2>>> G(N);
    rep(i, 0, M) {
        int u, v; cin >> u >> v; u--; v--;
        char c; cin >> c;
        int w = c - 'a';
        G[u].add({ v, w });
        G[v].add({ u, w });
    }
    //not slow
    rep(i, 0, N) {
        sort(begin(G[i]), end(G[i]), [&](auto a, auto b)
            { return a[0] == i && b[0] == i ? a[1] < b[1] : a[0] == i; });
    }
    // never tle never what???
    // WA
    vt<state> best(N);
    auto cmpp = [&](int i, int j) {
        const state *a = &best[i], *b = &best[j];
        for (int i = 25; i > -1; i--) {
            if (a->infi == i && b->infi == i) { //equivalent
                return i < j;
            }   else if (a->infi == i) {
                //if there's stuff after a, then a, otherwise b
                if (b->last >= i) return false;
                return true;
            }   else if (b->infi == i) {
                if (a->last >= i) return true;
                return false;
            }
            if (a->ct[i] != b->ct[i]) {
                return a->ct[i] < b->ct[i];
            }
        }
        return i < j;
    };
    //set is just constnat factor diff.
    set<int, decltype(cmpp)> s(cmpp);
    rep(i, 1, N) {
        best[i].ct[25] = MOD;
        best[i].ct[24] = MOD;
    }
    s.insert(0);
    vt<int> ans(N);
    vt<bool> done(N);

    while (!s.empty()) {
        int u = *s.begin(); s.erase(u);
        if (done[u]) continue;
        if (best[u].infi == -2) {
            rep(j, 0, 26) {
                ans[u] += best[u].ct[j];
            }
        }   else {
            ans[u] = -1;
        }
        done[u] = true;
        int self = best[u].last;
        int loop = 26;
        for (auto [v, w] : G[u]) {
            if (v == u) {
                loop = min(loop, w);
                continue;
            }
            state ns = best[u];
            if (ns.infi != -2) {

            }   else {
                if (w > self) { //this is probably always strictly more optimal
                    ns.infi = self;
                }   else if (w > loop) {
                    ns.infi = loop - 1;
                }   else {
                    ns.upd(w);
                }
            }
            if (cmp(ns, best[v])) {
                s.erase(v);
                best[v] = ns;
                s.insert(v);
            }
        }
    }

    rep(i, 0, N) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
/*
N, M
okay... cycles are allowed...
give me a moment i think
oh graph is connected good.
O(NM) is bellman ford?
damn yeah
this appears to be a "shortest paths" problem
bfs?
for a cycle, we find the maximum char along the cycle. 
then if we go through like any node, and any char along path after that has worse, then we can
just redo the cycle to make it better lexicographically? sort of it has to be like the same modulus thing
tihs requires thinking
okay consider a and b like the constraints
avoid b like the plague, but use it if we must
wait is there ever a point in using b?
there isn't.

because we can use the same edge multiple times that immediately invalidates it
we can therefore ignore cycles. on a path, we must be decreasing lexicographically.
good...?
we can compare states lexicographically by saying we have n z's, m y's, ...?
sure...? we still need to propagate "inf" states by saying 
which character we start producing cycle at.
now, we should be able to compare everything
verdict: it is chopped. this is really painful dijkstras.

please think
we knwo we have the right solution, but how do we do it without O(M log N * 26)?
also this tle'd on NM <= 5000 xd

lets think so for our graph
we know that paths take the form of some z's, some y's, ... some a's
IF they terminate
for nonterminating, goddamn it our comparison function is CORRECT.
to compare paths, rank them by when we visited them?

yes?
so we have "last char," "last visited," "infinity or not"
in a state?
how do we do comparisons?
compare the ranks of the "last visited" (like organize it into a tree basically)
compare last char/infinity
*/