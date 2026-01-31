#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    int M; cin >> M;
    string s; cin >> s;
    /*
    store for each copy, the smallest bounds modified
    if there are no inversions in [l, r] put like -1, -1
    if there are any, what is modified is the leftmost 1 to the rightmost 0
    */

    array<vt<int>, 2> occs{};
    rep(i, 0, N) {
        occs[s[i] - '0'].add(i);
    }
    set<ii<2>> uniq;
    rep(i, 0, M) { //ahahfeiwojaoijoxzvc
        int l, r; cin >> l >> r; l--; r--;
        //find leftmost one
        auto it = ranges::lower_bound(occs[1], l);
        if (it == occs[1].end()) {
            uniq.insert(ii<2>{ -1, -1 });
            continue;
        }
        int leftone = *ranges::lower_bound(occs[1], l);
        it = ranges::upper_bound(occs[0], r);
        if (it == occs[0].begin() || occs[0].empty()) {
            uniq.insert(ii<2>{ -1, -1 });
            continue;
        }
        int rightzero = *--it;
        if (s[rightzero] != '0') {
            uniq.insert(ii<2>{ -1, -1 });
            continue;
        }
        if (leftone > rightzero) {
            uniq.insert(ii<2>{ -1, -1 });
            continue;
        }
        uniq.insert({ leftone, rightzero });
    }
    cout << size(uniq) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}