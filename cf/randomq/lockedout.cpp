#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> {
    mt(int n = 0, const T &def = T()) : vt<T>(n, def) {} };

vector<int> sieve;

void era(int n) {
    sieve.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= n; j += i) {
            sieve[j] = i;
        }
    }
}


void solve() {
    int N; cin >> N;
    mt<int, 2> occ(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        occ[x].add(i);
    }
    for (int i = 0; i < N; i++) {
        occ[i].add(N);
    }

    int ans = 0;
    vt<int> dp;
    for (int i = 0; i < size(occ[0]); i++) {
        dp.add(size(occ[0]) - 1 - i);
    }

    for (int i = 1; i < N; i++) {
        vt<int> ndp { 0 };
        int k = size(occ[i - 1]) - 1;
        for (int j = size(occ[i]) - 2; j > -1; j--) { //choose this as FIRST
            int best = 0;
            while (k > -1 && occ[i - 1][k] > occ[i][j]) {
                best = max(best, dp[k--]);
            }
            ndp.add(max(ndp.back(), best) + 1);
        }
        ranges::reverse(ndp);
        ndp.back() = *ranges::max_element(dp);
        dp = ndp;
    }

    cout << N - (*ranges::max_element(dp)) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    era(200000);
    int T; cin >> T; while (T--) { solve(); }
}