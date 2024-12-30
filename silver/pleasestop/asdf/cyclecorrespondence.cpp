#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //match as many unseen together as possible
    vector<bool> Aseen(N), Bseen(N);
    vector<int> alabel(K), blabel(K);
    for (int i = 0; i < K; i++) {
        int x; cin >> x; x--;
        alabel[i] = x;
        Aseen[x] = true;
    }
    for (int i = 0; i < K; i++) {
        int x; cin >> x; x--;
        blabel[i] = x;
        Bseen[x] = true;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!Aseen[i] && !Bseen[i]) { ans++; }
    }
    //now check for both of A and B whether they work
    //wait label the differences between each other
    //
    auto run = [&]() {
        vector<int> apos(N), bpos(N);
        for (int i = 0; i < K; i++) {
            apos[alabel[i]] = i;
            bpos[blabel[i]] = i;
        }
        vector<int> diff(2 * N + 1);
        for (int i = 0; i < N; i++) {
            if (!Aseen[i] || !Bseen[i]) { continue; }
            diff[(apos[i] - bpos[i] + K) % K]++;
        }
        int res = 0;
        for (int x : diff) {
            res = max(res, x);
        }
        return res;
    };
    int best = run();
    reverse(alabel.begin(), alabel.end());
    best = max(best, run());
    cout << ans + best << "\n";
}