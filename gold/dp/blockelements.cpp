#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> pf(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pf[i + 1] = pf[i] + A[i];
    }

    int s = 0, e = pf[N];
    while (s + 1 < e) {
        int m = (s + e) / 2;  //limit
        bool valid = true;
        //so we can either be in a subarray, or block
        //we don't need to know the previous max subarray sum; we need current
        //we also need to know sum of blocked elements
        //minimize it
        vector<int> help;
        if (valid) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}