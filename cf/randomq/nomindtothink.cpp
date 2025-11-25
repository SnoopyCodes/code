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

void solve() {
    int N, K; cin >> N >> K;
    vt<int> A(N);
    for (int &i : A) { cin >> i; }
    ranges::sort(A);
    long pf[N + 1]{};
    for (int i = 0; i < N; i++) {
        pf[i + 1] = pf[i] + A[i];
    }


    long ans = 0;
    for (int i = 1; i < N - 1; i++) {
        int s = 1, e = min(N - i - 1, i); //this is valid [l, r]
        auto f = [&](int y) {
            long dec = (long) y * A[i] - (pf[i + y + 1] - pf[i + 1]);
            long to = min((long) i, (long) K * y);
            long inc = to * A[i] - pf[to];
            return inc + dec;
        };
        while (s < e) {
            int m = (s + e) / 2;
            if (f(m) < f(m + 1)) { s = m + 1; }
            else { e = m; }
        }
        ans = max(ans, f(s));
    }
    cout << ans + pf[N] << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}