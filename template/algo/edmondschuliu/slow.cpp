#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //all nodes should be reachable?
    auto edmonds_chu_liu = [](auto &&self, int N, vt<ii<3>> &E, int root) -> int { //num nodes, set of edges, root
        if (size(E) == 0) { return 0; }
        vt<bool> rem(size(E));
        vt<vt<ii<2>>> G;
        vt<int> min_e_to;
        for (int i = 0; i < size(E)) {
            auto [u, v, w] = E[i];
            if (v == root) {
                rem[i] = true;
            }   else {
                if (min_e_to[v] > w) {
                    G[u].add({ v, w });
                }
            }
        }
        //find any cycle within G
        //dfs from the root
        vt<bool> in_cyc;
        
        int min_in_cyc = -1;
        
        auto dfs = [&](auto &&self, int u) -> void {
            
        };
        
        vt<ii<3>> next;
        
        for (int i = 0; i < size(E); i++) if (!rem[i]) {
            auto [u, v, w] = E[i];
            if (in_cyc[u] && in_cyc[v]) { continue; }
            if (in_cyc[u]) {
                
            }   else if (in_cyc[v]) {
                
            }   else {
                next.add(E[i]);
            }
        }

    };
}