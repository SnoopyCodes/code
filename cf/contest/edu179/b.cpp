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
array<int, 10> fib{1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
void solve() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int w, l, h; cin >> w >> l >> h;
        int a = fib[N - 1], b = fib[N - 2];
        if (w < a || l < a || h < a) { cout << 0; continue; }
        if (w >= a + b || l >= a + b || h >= a + b) { cout << 1; }
        else { cout << 0; }
    }
    cout << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}