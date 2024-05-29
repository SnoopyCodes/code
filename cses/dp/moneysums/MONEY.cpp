#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    vector<bool> sums(N * 1000 + 1);
    sums[0] = 1;
    int total = 0;
    //ah but it is forgotten that we may only use one once..
    for (int i = 0; i < N; i++) {
        for (int x = N * 1000; x >= 0; x--) {
            if (x + coins[i] <= N * 1000 && sums[x] && !sums[coins[i] + x]) {
                sums[x + coins[i]] = true;
                total++;
            }
        }
    }
    cout << total << "\n";
    for (int i = 1; i <= N * 1000; i++) {
        if (sums[i]) { cout << i << " "; }
    }
}