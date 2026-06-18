#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
#define ld long double
ld qp(ld x, int p) { return p ? (p & 1 ? x : 1) * qp(x * x, p / 2) : 1; }


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int M, N; cin >> M >> N;
    /*
    uhh okay
    suppose we choose some roll r to be maximum with value x.
    then, all rolls 1.. r - 1 have less than x, and r + 1 ... n have <= x
    (x-1)**(r - 1) * (x)**(n-r) / M**N
    okay
    sum that for each x in 1...m and each r in 1...n pretty much.
    how?

    oh geometric sequences am i bad
    calculate the first term.
    x**(n - 1) / m**n
    / x
    * (x - 1)
    r = (x - 1) / x
    from that you get (1 - (x - 1) / x) * S = initial - final * (x - 1) / x
    initial = x**(n - 1) / m**n
    final = (x-1)**(n-1) / m**n
    */
    ld ans = qp(1.0 / M, N);
    for (int x = 2; x < M + 1; x++) {
        // for (int r = 0; r < N; r++) {
        //     ans += qp((ld) (x - 1) / M, r) * qp((ld) x / M, N - r - 1) / M * x;
        // }
        ld init = qp((ld) x / M, N - 1) / M;
        ld final = qp((ld) (x - 1) / M, N - 1) / M;
        ans += (init - final * (x - 1) / x) * x * x;
    }
    cout << ans << "\n";
    
}