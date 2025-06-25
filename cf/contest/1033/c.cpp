#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

void solve() {
    int N; std::cin >> N;
    long M; std::cin >> M;
    long initial;
    int root = -1;
    for (int i = N; i > 0; i--) {
        initial = (long) i * (i + 1) / 2 + (long) (N - i) * (i);
        int lb = i+ N - 1;
        if (initial >= M && lb <= M) {
            root = i;
            break;
        }
    }
    if (root == -1) { std::cout << -1 << "\n"; return; }

    std::cout << root << "\n";
    vector<int> par(N + 1, root);
    for (int i = N; i > 0; i--) {
        if (i == root) { continue; }
        if (initial - M > min(i - 1, root - 1)) {
            par[i] = 1;
            initial -= min(i - 1, root - 1);
        }   else if (initial - M > 0) {
            //any edge case here?
            //what if the difference makes it equal to itself?
            if (min(i, root) - (initial - M) == i) {
                par[i] = root;
            }   else {
                par[i] = min(i, root) - (initial - M);
            }
            break;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i == root) { continue; }
        std::cout << i << " " << par[i] << "\n";
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}