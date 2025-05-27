#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define rev(i,s,e) for(auto i=(s) - 1;i>=e;i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, vector<T>, std::less<T>()>;
template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

void solve() {
    int N, asjdfiojweiroqewpj; cin >> N >> asjdfiojweiroqewpj;
    vector<int> A(N), B(N);
    rep(i, 0, N) {
        cin >> A[i];
    }
    rep(i, 0, N) {
        cin >> B[i];
    }
    vector<long> pref_sum(2 * N + 1);
    rep(i, 0, 2 * N) {
        pref_sum[i + 1] = pref_sum[i] + B[i % N] - A[i % N];
    }
    std::deque<int> larger;
    int ans = 0;
    rev(i, 2 * N, 0) {
        while (!larger.empty() && pref_sum[larger.front()] <= pref_sum[i + 1]) { larger.pop_front(); }
        larger.push_front(i + 1);
        if (i < N) {
            int s = -1, e = larger.size();
            while (s + 1 < e) {
                int m = (s + e) / 2;
                int ind = larger[m];
                if (pref_sum[ind] - pref_sum[i] >= 0) { e = m; }
                else { s = m; }
            }
            ans = max(ans, larger[e] - i);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}