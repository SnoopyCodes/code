#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vec<vec<char>> S(N, vec<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    vec<vec<char>> T(M, vec<char>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> T[i][j];
        }
    }
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            bool valid = true;
            for (int k = i; k < i + M; k++) {
                for (int l = j; l < j + M; l++) {
                    if (S[k][l] != T[k-i][l-j]) { valid = false; }
                }
            }
            if (valid) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }

}