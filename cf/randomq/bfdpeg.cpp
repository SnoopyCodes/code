#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int ans = 0;
    vt<int> prep(2 * N);
    rep(i, 0, 2 * N) {
        prep[i] = i % N;
    }
    set<vt<int>> s;
    vt<int> perm(N);
    rep(i, 0, N) perm[i] = i;
    auto orig = perm;
    int rm = (N) / 2;
    do {
        vt<int> seq;
        vt<int> done(N);
        for (int &u : perm) {
            done[u] = true;
            seq.add(u);
            bool dd = false;
            rep(i, 0, N) {
                bool f = true;
                rep(j, i, i + rm) {
                    f &= done[prep[j]];
                }
                if (f) {
                    s.insert(seq);
                    dd = true;
                    break;
                }
            }
            if (dd) break;
        }
        ranges::next_permutation(perm);
    } while (perm != orig);
    cout << size(s) << "\n";
    // for (auto v : s) {
    //     for (int x : v) {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
}