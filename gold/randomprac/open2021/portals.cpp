#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

vt<int> root;

int find(int u) {
    return u == root[u] ? u : root[u] = find(root[u]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return false; }
    if (rand()) {
        root[u] = v;
    }   else {
        root[v] = u;
    }
    return true;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //chat can i read
    //every location to another..
    //subtasks?
    //test cases 2-4
    //c_v = 1
    //then always just choose one to swap edges with
    //can we maintain connectivity somehow?
    //wait, is it just straight up mst? i thought maybe, but not so straightforward
    int N; cin >> N;
    vt<int> cost(N);
    vt<ii<2>> edges(2 * N, { -1, -1 } ); //portal connects what
    vt<ii<4>> portals(N); //portals for each node
    /*
    
    */
   
    root = vt<int>(2 * N);
    iota(begin(root), end(root), 0);

    rep(i, 0, N) {
        cin >> cost[i];
        rep(j, 0, 4) cin >> portals[i][j], portals[i][j]--;
        rep(j, 0, 4) {
            bool d = edges[portals[i][j]][0] != -1;
            edges[portals[i][j]][d] = i;
            if (j >= 2) {
                edges[portals[i][j]][d] += N;
            }
        }
    }

    //draw connections.
    //2 * N locations, we said.
    int ncomp = 2 * N;
    for (auto [u, v] : edges) {
        ncomp -= merge(u, v);
    }
    //we have N candidates for merging
    vt<ii<3>> cand(N);
    rep(i, 0, N) {
        cand[i] = { cost[i], i, i + N };
    }
    sort(begin(cand), end(cand));
    int ans = 0;
    rep(i, 0, N) {
        auto [c, u, v] = cand[i];
        assert(v == u + N);
        if (merge(u, v)) {
            ans += c;
            ncomp--;
        }
    }

    cout << ans << "\n";

}