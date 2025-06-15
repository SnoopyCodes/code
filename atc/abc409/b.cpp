#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int best = 0;
    for (int i = 1; i <= N; i++) {
        int ct = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] >= i) { ct++; }
        }
        if (ct >= i) { best = i; }
    }
    cout << best << "\n";
}