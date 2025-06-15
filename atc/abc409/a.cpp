#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    std::string T, A; cin >> T >> A;
    bool y = false;
    for (int i = 0; i < N; i++) {
        if (T[i] == A[i] && T[i] == 'o') {
            y = true;
            break;
        }
    }
    cout << (y ? "Yes" : "No") << "\n";
}