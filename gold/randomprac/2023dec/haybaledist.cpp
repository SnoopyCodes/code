#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }
    sort(begin(A), end(A));
    vt<int> pf(N + 1);
    rep(i, 0, N) {
        pf[i + 1] = pf[i] + A[i];
    }

    //sum of convex functions are convex
    auto get = [&](int x, int a, int b) {
        //we are choosing x, go to y
        //if y is > then cost is b
        bool f = x == 8  && a == 1 && b == 2;
        int ind = --upper_bound(begin(A), end(A), x) - begin(A); //find last <=
        if (A[ind] > x) {
            return b * (pf[N] - x * N);
        }
        return a * ((ind + 1) * x - pf[ind + 1]) + b * (pf[N] - pf[ind + 1] - (N - ind - 1) * x);
    };
    int Q; cin >> Q;
    while (Q --> 0) {
        int a, b; cin >> a >> b;
        int s = 0, e = MOD;
        while (s + 2 < e) {
            int m = (s + e) / 2;
            if (get(m - 1, a, b) >= get(m, a, b)) {
                s = m;
            }   else {
                e = m;
            }
        }
        cout << min(get(s, a, b), get(s + 1, a, b)) << "\n";
    }

}