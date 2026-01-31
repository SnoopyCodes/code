#include <bits/stdc++.h>

using namespace std;

#define int long long //iff necessary e.g. addition under modulus unneeded
#define rep(i, a, b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;

template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

struct solver {

const int N = 5e5;

solver() {
    
}

};

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int T; cin >> T; while (T --> 0) solver();
    int N = 5;
    
    vt a(N, 0LL);
    a[0] = 5;
    
    vt<ii<2>> z(N);
    int n = 2, m = 3, k = 4;
    vt dp3d(n, vt(m, vt(k, 0)));
}