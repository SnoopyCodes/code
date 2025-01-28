#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> dp;
vector<int> seq;
vector<bool> is_prime;
vector<vector<int>> res;
int cnt = 0;
void go(int mask, int b) {
    if (b == -1) {
        reverse(seq.begin(), seq.end());
        res.push_back(seq);
        reverse(seq.begin(), seq.end());
    }   else {
        seq.push_back(b + 1);
        for (int x : dp[mask][b]) {
            go(mask ^ (1 << b), x);
        }
        seq.pop_back();
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    if (N == 1) { return 0; }
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    is_prime.resize(34);
    for (int p : primes) {
        is_prime[p] = true;
    }
    dp.resize(1 << N, vector<vector<int>>(N));
    dp[1][0].push_back(-1);
    for (int mask = 1; mask < 1 << N; mask++) {
        if (!(mask & 1)) { continue; }
        for (int b = 0; b < N; b++) {
            if (!(mask & 1 << b)) { continue; }
            if (dp[mask][b].empty()) { continue; }
            for (int p : primes) {
                if (p <= b + 1) { continue; }
                if (p > N + b + 1) { continue; }
                int d = p - b - 2;
                if (mask & 1 << d) { continue; }
                dp[mask ^ 1 << d][d].push_back(b);
            }
        }
    }
    for (int b = 0; b < N; b++) {
        if (!is_prime[b + 1 + 1]) { continue; }
        if (dp[(1 << N) - 1][b].empty()) { continue; }
        go((1 << N) - 1, b);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j] << " \n"[j == N - 1];
        }
    }
}