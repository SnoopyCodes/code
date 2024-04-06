#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N, K, M;
    cin >> N >> K >> M;
    //binary search on this
    //lambda > N - G - xq
    ll s = 0, e = N;
    while (s < e) {
        ll m = (e + s + 1) / 2;
        ll G = 0;
        ll days = 0;
        while ((N > G) / m > M) {
            ll give = max((N - G) / m, M);
            if (give < M) { days = (N - G + m - 1) / m; break; }

            ll time = (N-G) / give - m + 1;

            G += give;
            
        }
        if (days > K) { e = m-1; } 
        else { s = m; }
    }
    cout << s << "\n";
}