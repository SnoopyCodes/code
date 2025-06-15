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
    int N; cin >> N;
    vector<int> A(N);
    int prev = -1, len = 0;
    long cost = INF;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != prev) {
            if (prev != -1) {
                cost = min((long) (N - len) * prev, cost);
            }
            prev = A[i];
            len = 1;
        }   else {
            len++;
        }
    }
    cost = min((long) (N - len) * A[N - 1], cost);
    cout << cost << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}