#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

#define union zzzz
struct DSU {
    int N;
    vector<int> root, size;
    DSU(int _N):N(_N), root(N), size(N, 1)
    { std::iota(root.begin(), root.end(), 0); }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool union(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (size[ru] < size[rv]) { std::swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};

void solve() {
    int N; std::cin >> N;
    vector<vector<vector<int>>> mod(N, vector<vector<int>>(N));
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        for (int j = 1; j < N; j++) {
            mod[j][A[i] % j].push_back(i);
        }
    }
    DSU cc(N);
    vector<ints<2>> ans(N, {-1, -1});
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (mod[i][j].size() < 2) { continue; }
            int u = mod[i][j][0];
            for (int k = 1; k < mod[i][j].size(); k++) {
                int v = mod[i][j][k];
                if (cc.union(u, v)) {
                    ans[i] = { u, v };
                    break;
                }
            }
            if (ans[i] != ints<2>{ -1, -1 }) { break; }
        }
    }
    std::cout << "YES" << "\n";
    for (int i = 1; i < N; i++) {
        std::cout << ans[i][0]+1 << " " << ans[i][1]+1 << "\n";
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}