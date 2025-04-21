#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int N, K; cin >> N >> K;
    //if we choose a color from LEFT,
    //we don't want it from RIGHT, and vice versa
    //find the maximum such that we don't have that many matching
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }
    //sum the max from each first
    i64 ans = 0;
    vector<int> other;
    for (int i = 0; i < N; i++) {
        ans += max(L[i], R[i]);
        other.emb(min(L[i], R[i]));
    }
    //then sum the max of the others
    sort(other.begin(), other.end());
    reverse(other.begin(), other.end());
    for (int i = 0; i < K - 1; i++) {
        ans += other[i];
    }
    ans++;
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}