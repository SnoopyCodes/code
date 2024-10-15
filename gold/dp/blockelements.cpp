#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    vector<ll> pf(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pf[i + 1] = pf[i] + A[i];
    }
    //i don't suppose we can binary search on it?
    //we can either add to block, start subarray, or add to previous subarray
    //so we need to know the current subarray sum (cost) and the blocked elements so far
    //we can first get prefix sums going
    //best is our best possible goal
    //if any sums go over best then theres no point in continuing lmfao
    //wait bruh what
    //it doesn't work like that
    //maybe we can binary search on it
    //let dp[i] be the minimum cost of blocking 0...i ? it can't be that simple, can it?
    //fudge why was it binary search broooo im stoobid

    ll s = 0, e = pf[N];
    while (s + 1 < e) {
        ll m = (s + e) / 2;  //limit
        bool valid = true;
        //so we can either be in a subarray, or block
        //we don't need to know the previous max subarray sum; we need current
        //we also need to know sum of blocked elements
        //minimize it
        vector<ll> help;
        if (valid) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}