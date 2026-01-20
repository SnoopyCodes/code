#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*
    in the queue, sort it lexicographically. 
    we want to maintain the property
    "the first child that we propagate dp from with the longest path is the lexico min"
    return to rooted tree only.
    yeah no thats totally possible. we just do the reverse toposort
    when we propagate upwards, we maintain the position of the parent node in the queue last.
    that is the tiebreaker.
    */

    int N, M; cin >> N >> M;
    vt<vt<ii<2>>> G(N), H(N);
    vt<int> in(N), out(N);
    rep(i, 0, M) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        G[u].add({ v, w });
        H[v].add({ u, w });
        in[v]++;
        out[u]++;
    }

    vt<ii<2>> ans(N);
    vt<ii<3>> q; //{ current edge weight, previous position, u }
    rep(i, 0, N) {
        if (!out[i]) {
            q.add({ 0, (int) size(q), i });
        }
    }

    vt<vt<ii<3>>> candy(N);
    rep(d, 0, N) { //depth
        vt<ii<3>> newq;
        sort(begin(q), end(q));
        /*
        we need to reorder the candidates by first the CURRENT edge weights, then previous standing
        so we need { v, current edge weight, previous standing of u in queue, u }
        */

        vt<int> kill;
        vt<int> view;

        for (int i = (int) size(q) - 1; i > -1; i--) {
            auto [_, __, u] = q[i];
            for (auto [v, w] : H[u]) {
                out[v]--;
                view.add(v);
                candy[v].add({ w, i, u });
                if (out[v] == 0) {
                    kill.add(v);
                }
            }
        }
        for (int v : kill) {
            auto cand = candy[v];
            sort(begin(cand), end(cand));
            //wait only one should make it. what are we doing.
            auto [w, i, u] = cand[0];
            ans[v] = { d + 1, ans[u][1] + w };
            newq.add({ w, i, v });
        }
        for (int v : view) {
            candy[v].clear();
        }

        q = newq;
    }

    rep(i, 0, N) {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
}