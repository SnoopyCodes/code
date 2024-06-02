#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int A, B; cin >> A >> B;
    vector<vector<char>> v(N * A, vector<char>(N * B));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < A; k++) {
                for (int l = 0; l < B; l++) {
                    char c = (i + j) % 2 == 0 ? '.' : '#';
                    v[i * A + k][j * B + l] = c;
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}