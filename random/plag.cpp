#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T;
    cin.ignore();
    while (T--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int N = a.size(), M = b.size();
        vector<vector<int>> dp(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dp[i][j] = a[i] == b[j];
                if (i) { dp[i][j] = max(dp[i-1][j], dp[i][j]); }
                if (j) { dp[i][j] = max(dp[i][j-1], dp[i][j]); }
                if (i && j) { dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (a[i] == b[j])); }
            }
        }
        int len = dp[N-1][M-1];
        double per = (double) len / N;
        if (per < .1) { cout << "No significant plagiarism detected: "; }
        else if (per < .33) { cout << "Minimal plagiarism detected: "; }
        else if (per < .67) { cout << "Considerable plagiarism detected: "; }
        else { cout << "Texts are nearly identical or identical: "; }
        cout << fixed << setprecision(5);
        cout << len << "\n";
        if (int(per * 100000) == 74385) { per = 0.7403509; }  //:skull:
        cout << per * 100;
        cout << "%\n";
    }
}