#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    
    vector<int> C(N);
    long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        total += C[i];
    }
    K %= total;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (K == 0) { ans = i; break; }
        K -= C[i];
        if (K < 0) { ans = i; break; }
    }
    cout << ans << "\n";
}