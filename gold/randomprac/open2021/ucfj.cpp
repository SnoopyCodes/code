#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

vt<int> seg;
int sz;
void upd(int i, int v) {
    seg[i + sz] = v;
    for (i = (i + sz) / 2; i; i >>= 1) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}
int query(int l, int r) {
    int res = 0;
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //oh jeez what?
    //l < r btw.
    //ohh wait okay
    //for every cow, act it as right bound.
    //iterate leftwards
    //O(N^2)
    //seguh menteh treeuh
    //dao di shei ai shei hen shei pa, jie ju dong lie beng ta
    int N; cin >> N;
    seg = vt<int>(2 * N);
    sz = N;
    vt<vt<int>> occ(N);
    vt<int> B(N);
    vt<int> place(N);
    rep(i, 0, N) {
        cin >> B[i], B[i]--, place[i] = occ[B[i]].size(), occ[B[i]].add(i);
    }
    auto left = [&](int i) {
        return place[i] == 0 ? -1 : occ[B[i]][place[i] - 1];
    };
    auto right = [&](int i) {
        return place[i] + 1 == size(occ[B[i]]) ? N : occ[B[i]][place[i] + 1];
    };

    int ans = 0;
    vt<vt<int>> updates(N + 1);
    rep(i, 0, N) {
        for (int j : updates[i]) {
            upd(j, 0);
        }
        ans += query(left(i) + 1, i);
        upd(i, 1);
        updates[right(i)].add(i);
    }
    cout << ans << "\n";

}