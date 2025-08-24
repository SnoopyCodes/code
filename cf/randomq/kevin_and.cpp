// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define long long long
using namespace std;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;
template<int z> using ii = array<int, z>;

const int BIG = 2e9 + 1;
void solve() {
    int N, M, K; cin >> N >> M >> K;
    vt<int> A(N), B(M);
    array<vt<int>, 12> C;
    for (int i = 0; i <= 11; i++) {
        C[i].assign(N, BIG);
    }
    for (int &u : A) {
        cin >> u;
    }
    for (int &u : B) {
        cin >> u;
    }
    auto diff = [&](ii<2> x) {
        return C[x[1]][x[0]] - C[x[1] + 1][x[0]];
    };
    auto cmp = [&](ii<2> a, ii<2> b) {
        return diff(a) == diff(b) ? a[0] < b[0] : diff(a) < diff(b);
    };

    for (int mask = 0; mask < 1 << M; mask++) {
        int res = (1 << 31) - 1;
        for (int b = 0; b < M; b++) {
            if (mask & 1 << b) {
                res &= B[b];
            }
        }
        int bits = __builtin_popcount(mask);
        for (int i = 0; i < N; i++) {
            C[bits][i] = min(C[bits][i], A[i] & res);
        }
    }

    set<ii<2>, decltype(cmp)> s(cmp);
    for (int i = 0; i < N; i++) {
        s.insert({ i, 0 });
    }
    while (K--) {
        auto [i, j] = *--s.end();
        s.erase({ i, j });
        j++;
        A[i] = C[j][i];
        if (j < M) {
            s.insert({ i, j });
        }
    }
    cout << accumulate(A.begin(), A.end(), 0LL) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}
//conclusion: array vs vector, pretty significant?
//but it probably isn't enough to justify assigning array size 20 every time
//we need a thing.