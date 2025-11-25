// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,popcnt,lzcnt,bmi,bmi2")

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
const int  BIG = 1e9  +    7;

#define add push_back
template<class T, int D> struct mt : public vector<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vector<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vector<T> { using vector<T>::vector; };
template<class T> using vt = mt<T, 1>;

void solve() {
    int N, M; cin >> N >> M;
    bool transpose = N < M;
    if (transpose) { swap(N, M); }
    mt<bool, 2> G(N, M);
    for (int i = 0; i < (transpose ? M : N); i++) {
        for (int j = 0; j < (transpose ? N : M); j++) {
            char c; cin >> c;
            if (transpose) { G[j][i] = c == '1'; }
            else { G[i][j] = c == '1'; }
        }
    }

    mt<int, 2> ans(N, M, BIG);
    mt<int, 2> closest(M, M, -1);
    vt<int> close_upb(N, -1);
    for (int i = 0; i < N; i++) {
        vt<int> use_upb;
        for (int k = 1; k < M; k++) {
            for (int j = k - 1; j > -1; j--) {
                if (G[i][j] && G[i][k]) {
                    if (closest[j][k] != -1 && close_upb[closest[j][k]] != k) {
                        int area = (i - closest[j][k] + 1) * (k - j + 1);
                        for (int l = closest[j][k]; l <= i; l++) {
                            for (int m = j; m <= k; m++) {
                                ans[l][m] = min(ans[l][m], area);
                            }
                        }
                        close_upb[closest[j][k]] = k;
                        use_upb.add(closest[j][k]);
                    }
                    closest[j][k] = i;
                }
            }
        }
        for (int &x : use_upb) { close_upb[x] = -1; }
    }

    for (int i = 0; i < (transpose ? M : N); i++) {
        for (int j = 0; j < (transpose ? N : M); j++) {
            if (transpose) { cout << (ans[j][i] != BIG ? ans[j][i] : 0) << " "; }
            else { cout << (ans[i][j] != BIG ? ans[i][j] : 0) << " ";}
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // auto start = high_resolution_clock::now();

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T; cin >> T; while(T--) { solve(); }
    // auto end = high_resolution_clock::now();
    // double elapsed = duration<double, milli>(end - start).count();
    // cerr << "Time: " << elapsed << " ms\n";

}