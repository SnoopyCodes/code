#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    vec<long> A(N);
    long answer = 0;
    vec<int> bits(60);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int b = 0; b < 60; b++) {
            bits[b] += bool(A[i] & 1 << b);
        }
    }
    //N^2 is OK
    //use numbers as graph edges
    //then make a dp
    //dp[i][j] = best sequence including i
    //this should definitely work
    //uhh
    //is that right
    vec<arr<long, 2>> best(N + 1, {0, -INFL});
    best[0] = {0, 0};
    auto calc = [&](long mask, long sz) {
        return sz - __builtin_popcountll(mask);
    };
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            auto [mask, sz] = best[j];
            if (calc(best[i][0], best[i][1]) < calc(mask | A[i-1], sz + 1)) {
                best[i] = {mask | A[i-1], sz + 1};
            }
        }
    }
    long ans = 0;
    for (int i = 1; i <= N; i++) {
        cout << calc(best[i][0], best[i][1]) << "\n";
        ans = max(calc(best[i][0], best[i][1]), ans);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}