#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vec<vec<int>> seq(3, vec<int>(N));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> seq[i][j];
        }
        sort(seq[i].begin(), seq[i].end());
        reverse(seq[i].begin(), seq[i].end());
    }
    //do a bianry search
    long s = 0, e = 3e18;
    //?
    e++;
    auto calc = [&](int i, int j, int k) {
        return (long) seq[0][i] * seq[1][j]
        + (long) seq[1][j] * (long) seq[2][k] + (long) seq[2][k] * seq[0][i];
    };
    while (s + 1 < e) {
        long m = (s + e) / 2;
        int cnt = 0;
        int i = 0, j = 0, k = 0;
        while (cnt < K) {
            if (k == N) {
                j++; k = 0;
                if (calc(i, j, k) < m) {
                    i++;
                    j = 0;
                }
            }
            if (j == N) {
                i++; j = 0;
            }
            if (i == N) {
                break;
            }
            long val = calc(i, j, k);
            if (val >= m) { cnt++; }
            else { k = N - 1; }
            k++;
        }
        if (cnt < K) { e = m; }
        else { s = m; }
    }
    cout << s << "\n";
}