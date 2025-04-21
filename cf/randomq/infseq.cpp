#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rep(i, s, e) for (auto i = s; i < e; i++)
#define rev(i, s, e) for (auto i = s - 1; i >= e; i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

bool recur(i64 x, vector<bool> &pf) {
    if (x > 2 * (pf.size() - 1)) {
        if (x / 2 % 2 == 1) {  //all cancel out
            return pf[pf.size() - 1];
        }   else {
            return pf[pf.size() - 1] ^ recur(x / 2, pf);
        }
    }   else if (x > pf.size() - 1) {  //i think these are fine?
        return pf[x / 2];
    }   else {
        return pf[x] ^ pf[x-1];
    }
}

void solve() {
    int N; cin >> N;
    i64 P; cin >> P >> P; P;
    vector<bool> pf(N+1 + (N % 2 == 0));
    rep(i, 0, N) {
        int x; cin >> x;
        pf[i+1] = pf[i] ^ x;
    }
    if (N % 2 == 0) {
        pf[N + 1] = pf[N / 2] ^ pf[N];
    }
    cout << recur(P, pf) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}