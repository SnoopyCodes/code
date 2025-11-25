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

vt<int> rec(int N) {
    if (N == 0) { return {}; }
    int B = 0;
    while (1 << (B + 1) <= N) { B++; }
    vt<int> res(1 << B);
    for (int i = 0; i < (1 << B); i++) {
        res[i] = (((1 << B) - 1) ^ i);
    }
    for (int i = 1 << B; i < N; i++) {
        int j = i - (1 << B);
        int k = (1 << B) - 1 ^ j;
        res[k] = i;
    }
    auto add = rec(N - (1 << B));
    for (int x : add) { res.add(x); }
    return res;
}

void solve() {
    int N; cin >> N >> N; N++;

    long total = 0;
    vt<int> ans = rec(N);



    for (int i = 0; i < N; i++) {
        total += ans[i] | i;
    }

    cout << total << "\n";
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}