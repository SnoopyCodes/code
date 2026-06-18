#include <bits/stdc++.h>

using namespace std;

#define add push_back
    #define int long long
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
#define pt array<long double, 2>

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    long double X, Y; cin >> X >> Y;
    auto sqd = [&](pt a, pt b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    };
    pt O = { X, Y };
    #define ld long double
    ld close = MOD * MOD, far = 0;
    vt<pt> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i][0] >> P[i][1];
        far = max(far, sqd(P[i], O));
        close = min(close, sqd(P[i], O));
    }
    for (int i = 0; i < N; i++) {
        auto p = P[i], q = P[(i + 1) % N];
        //kid taking multivariable calculus forgets unit 1
        //cross product = area of parallelogram, thus just cross / dist gives solution.
        ld dist = sqrtl(sqd(p, q));
        /*
        ok how do i bound it though?
        */
        ld cross = abs(p[0] * q[1] - q[0] * p[1]);
        ld fin = cross / dist;
        cout << fin << endl;
        close = min(close, fin * fin);
    }

    double between = far - close;
    printf("%.20f\n", between * 3.1415926535897932364626);
}