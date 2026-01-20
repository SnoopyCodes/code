#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

vt<ii<2>> construct(vt<bool> s) {

    int N = size(s);
    //eliminate 1s
    vt<ii<2>> ops;
    rep(i, 0, N) {
        if (s[i]) {
            rep(j, i + 1, N) {
                if (s[j]) {
                    ops.add({ i, j });
                    rep(k, i, j + 1) {
                        s[k] = !s[k];
                    }
                    break;
                }
            }
        }
    }
    //very hard problem.
    int ind = -1;
    rep(i, 0, N) {
        if (s[i]) {
            ind = i;
            break;
        }
    }
    if (ind > 1) {
        ops.add({ 0, ind - 1 });
        ops.add({ 0, ind });
    }   else if (ind > -1) {
        ops.add({ ind + 1, N - 1 });
        ops.add({ ind, N - 1 });
    }
    return ops;
}

void solve() {
    int N; cin >> N;
    string s, t; cin >> s >> t;
    auto tvtb = [](string s) {
        vt<bool> n; rep(i,0,size(s)) n.add(s[i] == '1'); return n;
    };
    auto first = construct(tvtb(s));
    auto second = construct(tvtb(t));
    ranges::reverse(second);
    cout << size(first) + size(second) << "\n";
    rep(i, 0, size(first)) {
        cout << first[i][0]+1 << " " << first[i][1]+1 << "\n";
    }
    rep(i, 0, size(second)) {
        cout << second[i][0]+1 << " " << second[i][1]+1 << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}