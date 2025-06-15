#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

#define long long long
#define rsz resize
#define max_heap std::priority_queue

const int MOD = 1e9 + 7;
const long INF = 4e18;

template<typename T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;
template<typename T> T mvec(T def) { return def; }
template<typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}


void solve() {
    int N, M, L; cin >> N >> M >> L;
    vector<vector<int>> G(N);
    vector<int> A(L);
    int total = 0, min_odd = MOD;
    for (int i = 0; i < L; i++) {
        cin >> A[i];
        total += A[i];
        if (A[i] & 1) { min_odd = min(min_odd, A[i]); }
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //the graph is connected.
    //this is true
    //check if the graph is bipartite
    //the furthest we can go is like
    //the sum of all our multiset.
    //if the graph is bipartite and we only have evens we can only hit some
    //bfs to calculate distances
    //in odds and evens
    //and once we do this, what?
    //if we only have evens, we can hit all the evens
    //with dist <= sum
    //if we have at least one odd
    //up to (sum - odd) we can get all
    //and we can get sum with parities matching sum


    auto calc = [&](bool f) {
        //0 is done, 1 is fake
        array<vector<int>, 2> done({ vector<int>(N, 2 * MOD), vector<int>(N, 2 * MOD) });
        std::queue<array<int, 2>> q;
        if (f) {
            for (int v : G[0]) {
                done[0][v] = 1;
                q.push({ v, 0 });
            }
        }   else {
            done[0][0] = 0;
            q.push({ 0, 0 });
        }
        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();
            // if (f && t) { cout << u << "\n"; }
            for (int v : G[u]) {
                // if (f && t && u == 4) { cout << v << "\n"; }
                if (done[!t][v] != 2 * MOD) { continue; }
                done[!t][v] = done[t][u] + 1;
                q.push({ v, !t });
            }
        }
        return done[0];
    };

    auto even = calc(0);
    auto odd = calc(1);
    vector<bool> ok(N);
    for (int i = 0; i < N; i++) {
        // cout << even[i] << " " << odd[i] << "\n";
        if (min_odd != MOD && min(even[i], odd[i]) <= total - min_odd) { ok[i] = true; }
        else if (((total & 1) == 1) && odd[i] <= total) { ok[i] = true; }
        else if (((total & 1) == 0) && even[i] <= total) { ok[i] = true; }
    }
    for (int i = 0; i < N; i++) {
        cout << ok[i];
    }
    cout << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}