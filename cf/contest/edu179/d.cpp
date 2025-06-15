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
    int N, M; cin >> N >> M;
    vector<int> floor(M);
    for (int i = 0; i < M; i++) {
        int f; cin >> f;
        floor[i] = f;
    }
    sort(floor.begin(), floor.end());
    //greedily pair them largest to smallest
    //this would be the case
    //but they are available again during halves..
    int cur = 0;
    for (int i = 0; i < N; i += 2) {
        int first = floor[cur], last = floor[M - cur - 1];
        cur++;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 3; j++) {
                cout << first << " " << last << " \n"[j == 2];
            }
            swap(first, last);
            if (N - i == 1) { break; }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}