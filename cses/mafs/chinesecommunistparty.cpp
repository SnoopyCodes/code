#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int N; cin >> N;
    int M = 1e6 + 1;
    vt<int> ct(M);
    rep(i, 0, N) {
        int x; cin >> x; ct[x]++;
    }

    vt<int> mults(M);
    rep(i, 1, M) {
        for (int j = i; j < M; j += i) {
            mults[i] += ct[j];
        }
    }

    vt<int> val(M); //for how many pairs is this the gcd?
    for (int i = M - 1; i > 0; i--) {
        val[i] = mults[i] * (mults[i] - 1) / 2;
        for (int j = 2 * i; j < M; j += i) {
            val[i] -= val[j];
        }
    }
    cout << val[1] << "\n";
    
}