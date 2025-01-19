//https://oj.uz/problem/view/IZhO14_bank

#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> salaries(N);
    vector<int> notes(M);
    for (int i = 0; i < N; i++) {
        cin >> salaries[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> notes[i];
    }
    vector<array<int, 2>> dp(1 << M, {-1, 0});
    for (int mask = 0; mask < 1 << M; mask++) {
        auto [pf, sum] = dp[mask];
        for (int b = 0; b < M; b++) {
            if (mask & 1 << b) { continue; }
            if (dp[mask][0] == N - 1) { dp[mask | 1 << b][0] = N - 1; continue; }
            int pfb = pf, sumb = sum + notes[b];
            if (sumb == salaries[pfb + 1]) { pfb++; sumb = 0; }
            if (dp[mask | 1 << b][0] <= pfb) { dp[mask | 1 << b] = {pfb, sumb}; }
        }
    }

    cout << (dp[(1 << M) - 1][0] == N - 1 ? "YES" : "NO") << "\n";
}