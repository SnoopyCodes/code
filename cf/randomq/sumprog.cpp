#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
struct chash {
    int operator()(ii<2> x) const { return x[0]* 31 + x[1]; }
};

void solve() {
    int N, Q; cin >> N >> Q;
    vt<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }

    auto build = [&](int s, int d) {
        int rem = s % d;
        vt<int> base;
        // cout << "building ";
        for (int i = rem; i < N; i += d) {
            // cout << i << "_";
            base.add(A[i]);
            // cout << A[i] << " ";
        }
        // cout << "\n";
        int sz = size(base);
        vt<int> psum(sz + 1), csum(sz + 1);
        rep(i, 0, sz) {
            psum[i + 1] = psum[i] + base[i];
            csum[i + 1] = csum[i] + base[i] * (i + 1);
        }

        return array<vt<int>, 2> { csum, psum };
    };

    auto get_sum = [&](vt<int> &csum, vt<int> &psum, int l, int r) {
        return csum[r + 1] - csum[l] - l * (psum[r + 1] - psum[l]);
    };

    vt<vt<ii<3>>> qs(N + 1);

    rep(i, 0, Q) {
        int s, d, k; cin >> s >> d >> k; s--;
        qs[d].add({ s, k, i });
    }

    vt<int> ans(Q);

    rep(i, 1, N + 1) {
        if (qs[i].empty()) { continue; }
        sort(begin(qs[i]), end(qs[i]), [&](auto a, auto b){ return a[0] % i < b[0] % i; });
        int r = -1;
        int j = 0;
        array<vt<int>, 2> res{};
        while (j < size(qs[i])) {
            if (r != qs[i][j][0] % i) {
                r = qs[i][j][0] % i;
                res = build(qs[i][j][0], i);
            }
            auto [s, k, q] = qs[i][j];
            int d = i;
            ans[q] = get_sum(res[0], res[1], s / d, k - 1 + s / d);
            j++;
        }
    }

    rep(i, 0, Q) {
        cout << ans[i] << " ";
    }

    cout << "\n";

    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}