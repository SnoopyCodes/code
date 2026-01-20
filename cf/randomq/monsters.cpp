#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

vector<int> dsu;
void init(int N) { dsu = vector<int>(N); while (N--) dsu[N] = N; }
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void unite(int u, int v) {
    u = find(u), v = find(v);
    dsu[v] = u;
}

void solve() {
    int N, M; cin >> N >> M;
    init(N);
    vt<set<int>> visiteds(N);
    vt<vt<int>> G(N);
    vt<int> danger(N);

    vt<set<ii<2>>> sets(N);
    vt<int> level(N);
    set<int> look;

    rep(i, 0, N) {
        cin >> danger[i];
        if (danger[i] == 0) {
            sets[i].insert({ danger[i], i });
            look.insert(i);
        }
    }

    rep(i, 0, M) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }

    while (!look.empty()) { //there *should* only ever be a need to look at each parent once.
        //MY SOLDIERS EXPAND
        int i = *look.begin();
        look.erase(i);
        if (find(i) != i) {
            continue;
        }
        while (!sets[i].empty() && level[i] >= (*sets[i].begin())[0]) {
            auto [dg, u] = *sets[i].begin(); sets[i].erase(sets[i].begin());
            int ru = find(u);
            bool uniting = size(visiteds[ru]);
            unite(i, ru);
            if (uniting) {
                if (i == ru) {
                    continue;
                }
                level[i] += level[ru];
                for (auto [d, v] : sets[ru]) {
                    if (!visiteds[i].count(v)) {
                        sets[i].insert({ d, v });
                    }
                }
                for (int v : visiteds[ru]) {
                    visiteds[i].insert(v);
                }
                visiteds[ru].clear();
                sets[ru].clear();
                look.erase(ru);
            }   else {
                level[i]++;
                visiteds[i].insert(u);
                for (int v : G[u]) {
                    if (!visiteds[i].count(v)) {
                        sets[i].insert({ danger[v], v });
                    }
                }
            }
        }
    }

    bool ok = true;
    rep(i, 1, N) {
        ok &= find(i) == find(0);
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T -- > 0) solve();
    //i think we can just act as if we start from all 0s
    //then just dsu whee whee whee whee whee
    /*
    use a priority queue. have a "parent" vertex (which is the 0) that we 
    update with # of monsters defeated
    use individual priorityq/set for all 0s?
    thats probably fine
    if a node is defeated and in another 0s view
    we should merge the two 0s real ong ong
    */
}