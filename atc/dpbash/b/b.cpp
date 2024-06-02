#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector<int> leastcost(N, 1e9+2);
    leastcost[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K && j + i < N; j++) {
            leastcost[i + j] = min(leastcost[i+j], leastcost[i] + abs(v[i] - v[i + j]));
        }
    }
    cout <<  leastcost[N-1];
}