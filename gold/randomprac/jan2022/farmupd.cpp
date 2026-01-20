#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

const int N = 2e5 + 5;
int par[N], sz[N];
int edges[N][2], upd[N][3];
bool active[N];
bool rem_init_graph[N];
bool init_unactive[N];
vt<int> comp_need[N];
int ans[N];
int M = 0, U = 0;
void init(int n) { while (n--) par[n] = n, sz[n] = 1; }
int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
bool merge(int u, int v, int t) {
    u = find(u), v = find(v);
    if (u == v) {
        return false;
    }
    if (active[v] || active[u]) {
        if (active[v]) swap(u, v);
        assert(comp_need[u].empty());
        for (int i : comp_need[v]) {
            ans[i] = t;
        }
        par[v] = u;
    }   else {
        if (size(comp_need[u]) < size(comp_need[v])) { swap(u, v); }
        for (int i : comp_need[v]) {
            comp_need[u].add(i);
        }
        comp_need[v].clear(); //ye why not
        par[v] = u;
    }
    return true;
}
void activate(int u, int t) {
    u = find(u);
    if (active[u]) {
        return;
    }
    assert(size(comp_need[u]));
    for (int i : comp_need[u]) {
        ans[i] = t;
    }
    comp_need[u].clear();
    active[u] = true;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    init(N);
    //so everything is active
    //what ze hell
    //okay but very importantly we mainly want to consider
    //activity levels. 
    //oh! deactivation for each i may only happen once, and never reactivated
    //finally, only active farms are ever merged..
    //that means... nothing with regards to connectivity are changed!!!
    //we iterate backwards in order of queries. 
    //maintain for each cc if it has an active component or not
    //D u -> reactivate cc[u]
    //A u v -> "remove" the edge between u and v (do nothing??)
    //R e -> find the edge e, and add the edge.
    int n, Q; cin >> n >> Q;
    rep(q, 0, Q) {
        char c; cin >> c;
        int type = c == 'A' ? 0 : c == 'D' ? 1 : 2;
        if (type == 0) {
            cin >> edges[M][0] >> edges[M][1], edges[M][0]--, edges[M][1]--;
            M++;
        }   else {
            upd[U][0] = type;
            cin >> upd[U][1]; upd[U][1]--;
            if (type == 1) {
                init_unactive[upd[U][1]] = true;
            }   else {
                rem_init_graph[upd[U][1]] = true;
            }
            upd[U][2] = q;
            U++;
        }
    }

    rep(i, 0, n) {
        active[i] = !init_unactive[i];
        if (!active[i]) {
            comp_need[i].add(i);
        }   else {
            ans[i] = Q;
        }
    }
    rep(i, 0, M) {
        if (!rem_init_graph[i]) {
            auto [u, v] = edges[i];
            merge(u, v, Q); //Q, because these are always set
        }
    }
    /*
    we can do stuff now, but how do we find for each i, the time it was first activated?
    i think our best bet is small to large merging in terms of convenience.
    */

    while (U --> 0) {
        int type = upd[U][0];
        int t = upd[U][2];
        if (type == 1) {
            //activate
            int u = upd[U][1];
            activate(u, t);
        }   else {
            auto [u, v] = edges[upd[U][1]];
            merge(u, v, t);
        }
    }
    rep(i, 0, n) {
        cout << ans[i] << "\n";
    }
}