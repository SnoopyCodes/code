#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int N; cin >> N;
    vector<array<int, 2>> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i][0] >> pts[i][1];
    }
    //consider a point
    //it must have had originally some center adjacent to itself
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}