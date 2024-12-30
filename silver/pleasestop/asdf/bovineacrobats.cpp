#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    //iterate over weights
    vector<array<int, 2>> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i][0] >> weights[i][1];
    }
    sort(weights.begin(), weights.end());
    reverse(weights.begin(), weights.end());
    //create {weights, freq} towers
    //add onto the fattest, remove the heaviest
    //oh wait we can't repush them to be different
    queue<array<int, 2>> q;
    int towers = 0;
    long count = 0;
    for (int i = 0; i < N; i++) {
        auto [w, f] = weights[i];
        int totalmake = 0;
        if (towers < M) {
            int make = min(M - towers, f);
            totalmake += make;
            count += make;
            towers += make;
            f -= make;
        }
        while (!q.empty() && q.front()[0] >= K + w && f) {
            int make = min(q.front()[1], f);
            if (make == q.front()[1]) { q.pop(); }
            else { q.front()[1] -= make; }
            totalmake += make;
            count += make;
            f -= make;
        }
        q.push({w, totalmake});
    }
    cout << count << "\n";
}