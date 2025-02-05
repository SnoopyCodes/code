#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int count = 0;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            vector<int> B;
            for (int i = l; i <= r; i++) {
                B.push_back(A[i]);
            }
            sort(B.begin(), B.end());
            for (int i = 0; i < r - l; i++) {
                count += B[i + 1] - B[i] > 1;
            }
        }
    }
    cout << count << "\n";
}