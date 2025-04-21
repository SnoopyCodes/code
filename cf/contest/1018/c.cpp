#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r) {
    return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...));
}

void solve() {
    int N; cin >> N;
    auto heights = mvec<int>(N, N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> heights[i][j];
        }
    }
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    vector<array<i64, 2>> row(N, {INF, INF}), col(N, {INF, INF});
    row[0][0] = 0;
    col[0][0] = 0;
    row[0][1] = A[0];
    col[0][1] = B[0];
    for (int i = 1; i < N; i++) {
        array<bool, 4> rok{1, 1, 1, 1}, cok{1, 1, 1, 1};
        for (int j = 0; j < N; j++) {
            //for row: if the [i-1][j] is same, we want one to be increase
            //if the [i-1][j] is 1 less we can increase or if not then we take where it doesnt
            int d = heights[i][j] - heights[i-1][j];
            if (d == -1) { rok[1] = false; }
            if (d == 0) { rok[0] = rok[3] = false; }
            if (d == 1) { rok[2] = false; }

            d = heights[j][i] - heights[j][i-1];
            if (d == -1) { cok[1] = false; }
            if (d == 0) { cok[0] = cok[3] = false; }
            if (d == 1) { cok[2] = false; }
        }
        //if same, one of us must be, 01, 10
        //if -1, our take they take, 11, 10, 00
        //if 1, their take we take, 00, 11, 01
        //say we don't take
        for (int l = 0; l < 4; l++) {
            if (rok[l]) {
                bool tk = l & 1, p = l & 2;
                row[i][tk] = min(row[i][tk], tk * A[i] + row[i-1][p]);
            }
            if (cok[l]) {
                bool tk = l & 1, p = l & 2;
                col[i][tk] = min(col[i][tk], tk * B[i] + col[i-1][p]);
            }
        }
    }
    i64 ans = min(row[N-1][0], row[N-1][1]) + min(col[N-1][0], col[N-1][1]);
    if (ans >= INF) { cout << -1 << "\n"; }
    else { cout << ans << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}