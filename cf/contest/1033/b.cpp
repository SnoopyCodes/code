#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

void solve() {
    int N, S; std::cin >> N >> S;
    int ct = 0;
    for (int i = 0; i < N; i++) {
        int dx, dy, x, y; std::cin >> dx >> dy >> x >> y;
        if (dx == dy) {
            if (x == y) {
                ct++;
            }
        } else {
            if (x + y == S) {
                ct++;
            }
        }
    }
    std::cout << ct << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}