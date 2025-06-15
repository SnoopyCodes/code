#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;;

void solve() {
    int N; std::cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = j;
        }
    }
    std::cout << 2 * (N) << "\n";
    for (int i = 0; i < N; i++) {
        std::cout << i + 1 << " " << min(N, i + 2) << " " << N << "\n";
        std::cout << i + 1 << " " << 1 << " " << i + 1 << "\n";
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}