#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //wtf free
    array<vt<int>, 10> occ_in_pref;
    rep(i, 0, 10) occ_in_pref[i] = vt<int>(N);
    int best = -1;
    rep(i, 0, N) {
        int u; cin >> u; u--;
        if (i > 0) rep(v, 0, 10) {
            occ_in_pref[v][i] = occ_in_pref[v][i - 1];
        }
        occ_in_pref[u][i]++;
        
        map<int, int> m;
        int nm = 0;
        rep(v, 0, 10) {
            if (occ_in_pref[v][i] != 0)
            m[occ_in_pref[v][i]]++, nm++;
        }
        //choose one to decrement. basically either one of them is 1 and all others same
        //or it is 1 more than others.
        if (m.size() > 2) {
            continue;
        }
        if (m.size() == 1) { //if all are the same
            //if all just one, okay. otherwise, if they all frequency one, okay
            if ((*m.begin()).second == 1 || m[1] == nm) {
                best = i;
            }
            continue;
        }
        auto [a, af] = *m.begin();
        auto [b, bf] = *m.rbegin();
        if (a + 1 == b && bf == 1 || a == 1 && af == 1) {
            best = i;
        }
    }
    cout << best + 1 << "\n";

}