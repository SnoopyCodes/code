#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

void solve() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    int last = -1;
    bool bad = false;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != -1) {
            B[i] = A[i];
            if (last == -1) {
                for (int j = i - 1; j >= 0; j--) {
                    if (j - i & 1) {
                        B[j] = B[j + 1] * 2;
                    }   else {
                        B[j] = B[j + 1] / 2;
                    }
                }
            }   else {
                int diff = i - last;
                int x = min(A[i], A[last]), xx = 0;
                int y = max(A[i], A[last]), yy = 0;
                while (__builtin_clz(y) < __builtin_clz(x)) {
                    y /= 2;
                    yy++;
                }
                while (x != y) {
                    x /= 2;
                    xx++;
                    y /= 2;
                    yy++;
                }
                if ((xx + yy) % 2 != diff % 2 || diff < (xx + yy)) {
                    bad = true;
                    continue;
                }
                int j = last + 1, k = i - 1;
                if (A[last] < A[i]) {
                    for (j = last + 1; xx > 0; xx--, j++) {
                        B[j] = B[j - 1] / 2;
                    }
                    for (; yy > 0; yy--, k--) {
                        B[k] = B[k + 1] / 2;
                    }
                }   else {
                    for (j = last + 1; yy > 0; yy--, j++) {
                        B[j] = B[j - 1] / 2;
                    }
                    for (; xx > 0; xx--, k--) {
                        B[k] = B[k + 1] / 2;
                    }
                }
                for (int l = j; l <= k; l += 2) {
                    B[l] = B[l - 1] * 2;
                    B[l + 1] = B[l - 1];
                }
            }
            last = i;
        }
    }
    if (last == -1) {
        for (int i = 0; i < N; i++) {
            if (i & 1) { B[i] = 1; }
            else { B[i] = 2; }
        }
    }   else {
        for (int i = last + 1; i < N; i++) {
            if (i - last & 1) { B[i] = B[i - 1] * 2; }
            else { B[i] = B[i - 1] / 2; }
        }
    }
    //what in the silver ptsd
    //split into ranges between continuous thing
    if (bad) {
        cout << -1 << "\n";
    }   else {
        for (int i = 0; i < N; i++) {
            cout << B[i] << " \n"[i == N - 1];
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}