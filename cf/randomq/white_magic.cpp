#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rep(i,s,e) for(auto i=(s);i<(e);i++)
#define rev(i,s,e) for(auto i=(s) - 1;i>=(e);i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back


void solve() {
    int N; cin >> N;
    vector<int> A;
    int count = 0;
    bool seen = false;
    rep(i, 0, N) {
        int x; cin >> x;
        if (x || !seen) {
            count += x != 0;
            seen |= x == 0;
            A.emb(x);
        }
    }
    N = A.size();
    vector<int> pref_min(N, MOD);
    rep(i, 0, N) {
        pref_min[i] = A[i];
        if (i) { pref_min[i] = min(pref_min[i], pref_min[i-1]); }
    }

    bool ok = seen;
    seen = false;
    vector<bool> done(N + 1);
    int mex = 0;
    rev(i, N, 0) {
        while (done[mex]) { mex++; }
        if (mex > pref_min[i]) { ok = false; break; }
        if (A[i] < N) { done[A[i]] = true; }
    }

    cout << count + ok << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}