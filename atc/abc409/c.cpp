#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout;

#define long long long

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int L, N; cin >> N >> L;
    //bruh why so weird
    vector<int> P(N);
    vector<int> ct(L);
    ct[0] = 1;
    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        P[i] = (P[i-1] + x) % L;
        ct[P[i]]++;
    }
    long ans = 0;
    if (L % 3 == 0) {
        for (int i = 0; i < L / 3; i++) {
            ans += (long) ct[i] * ct[i + (L / 3)] * ct[i + 2 * L / 3];
        }
    }
    cout << ans << "\n";
    
}