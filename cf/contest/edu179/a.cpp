#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rsz resize

template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;
template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

void solve() {
    int X; cin >> X;
    int ans = 0;
    array<int, 3> A{};
    int cur = 0;
    while (*std::min_element(A.begin(), A.end()) < X) {
        int mxchange = 2 * min(A[(cur + 1) % 3], A[(cur + 2) % 3]) + 1;
        if (A[cur] < X) {
            ans++;
            A[cur] = min(X, mxchange);
        }
        cur = (cur + 1) % 3;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}