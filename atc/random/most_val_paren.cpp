#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rep(i,s,e) for(auto i=(s);i<(e);i++)
#define rev(i,s,e) for(auto i=(s) - 1;i>=(e);i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

void solve() {
    int N; cin >> N;
    long total = 0;
    vector<int> A(2 * N);
    std::set<array<int, 2>> ms;
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
        total += A[i];
        ms.emp(ta(A[i], i));
    }
    int cur = 2 * N - 1;
    vector<bool> done(2 * N);
    while (!ms.empty()) {
        while (done[cur]) { cur--; }
        auto [v, i] = *--ms.end(); ms.erase(--ms.end());
        if (i == cur) { continue; }
        total -= v;
        done[cur] = true;
        ms.erase(ta(A[cur], cur));
        done[i] = true;
    }
    cout << total << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}