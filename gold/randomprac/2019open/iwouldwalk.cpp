#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("walk.in", "r", stdin);
    //freopen("walk.out", "w", stdout);
    int N, K; cin >> N >> K;
    //wtf is this formula
    //ok we can calculate distances
    //wait MST is also the maximum bottleneck tree thing
    const ll c1 = 2019201913;
    const ll c2 = 2019201949;
    const int MOD = 2019201997;
    vector<vector<ll>> dist(N, vector<ll>(N));
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ll walk = (c1 * (i + 1) + c2 * (j + 1)) % MOD;
            dist[i][j] = walk;
            dist[j][i] = walk;
        }
    }
    //suppose we binary search on this M
    //then form groups bc any two that have length less than len must be combined together
    //i think this is pretty trivial?
    //oh they made bounds to tle apparently wtf
    //ok then what other ways are there
    //suppose we use the smallest one then
    //
}