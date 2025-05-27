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
    //O(N^2M^2) is ok
    int N, M, K; cin >> N >> M >> K;
    //modify with extra dimension for # of times operation on this row done
    auto grid = mvec<int>(N, M, 0);
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> grid[i][j];
        }
    }
    auto least_cost = mvec<long>(N, M, M, INF);
    rep(i, 0, M) {
        least_cost[0][0][i] = grid[0][i] + (long) K * i;
    }
    rep(i, 0, N) {
        rep(j, 0, M) {
            //2 states: push right, push down
            if (i < N - 1) {
                long minv = *min_element(least_cost[i][j].begin(), least_cost[i][j].end());
                rep(k, 0, M) {
                    least_cost[i + 1][j][k] = minv + grid[i + 1][(j + k) % M] + (long) K * k;
                }
            }
            //push right
            if (j < M - 1) {
                rep(k, 0, M) {  //each state
                    int cost = grid[i][(j + k + 1) % M];
                    least_cost[i][j + 1][k] = min(least_cost[i][j + 1][k], least_cost[i][j][k] + cost);
                }
            }
        }
    }
    cout << *min_element(least_cost[N - 1][M - 1].begin(), least_cost[N - 1][M - 1].end()) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}