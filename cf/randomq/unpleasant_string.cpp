#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    string s; cin >> s;
    auto conv = [](string s) {
        vt<int> a(size(s)); rep(i, 0, size(s)) a[i] = s[i] - 'a'; return a;
    };
    vt<int> A = conv(s);
    vt<vt<int>> occ(K);
    rep(i, 0, N) {
        occ[A[i]].add(i);
    }
    vt<int> ans(N + 2);
    vt<bool> seen(K);
    int cnt = 0;
    ans[N] = 1;
    for (int i = N - 1; i > -1; i--) {
        bool inc = false;
        if (!seen[A[i]]) {
            cnt++;
            seen[A[i]] = true;
            if (cnt == K) {
                rep(i,0,K) seen[i] = 0;
                inc = true;
                cnt = 0;
            }
        }
        ans[i] = ans[i + 1] + inc;
    }
    int Q; cin >> Q;
    while (Q --> 0) {
        string t; cin >> t;
        auto B = conv(t);
        int cur = -1;
        rep(i, 0, size(B)) {
            cur = ranges::upper_bound(occ[B[i]], cur) - begin(occ[B[i]]);
            if (cur == size(occ[B[i]])) {
                cur = N;
                break;
            }   else {
                cur = occ[B[i]][cur];
            }
        }
        cout << ans.at(cur + 1) << "\n";
    }
}