#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
#define tp template
tp<int z> using ints = array<int, z>;
tp<int z> using longs = array<long, z>;

tp<class T> using vt = vector<T>;
tp<class T> using vv = vt<vt<int>>;
// tp<class T> istream& operator>>(istream& in, vt<T> &v) { for (T &x : v) { in >> x; } return in; }
// tp<int z> istream& operator>>(istream& in, ints<z> &a) { for (T &x : a) { in >> x; } return in; }
// tp<class T> ostream& operator<<(ostream& out, vt<T> &v) { for (int i = 0; i < v.size(); i++) {
//     out << v[i] << " \n"[i == v.size() - 1]; }
//     return out;
// }

vt<int> C;
int N, B, X;
long f(int k) {
    long res = (long) -(k - 1) * X;
    for (auto c : C) {
        long max_plus = (long) c * (c - 1) / 2;
        int q = c / k;
        int r = c % k;
        int just_q = k - r;
        max_plus -= (long) q * (q - 1) / 2 * just_q;
        max_plus -= (long) (q + 1) * q / 2 * r;
        res += max_plus * B;
    }
    return res;
}

void solve() {
    cin >> N >> B >> X;
    C.resize(N);
    for (auto &x : C) { cin >> x; }
    
    int s = 1, e = BIG;
    while (s + 2 < e) {
        int m = (s + e) / 2;
        if (f(m - 1) < f(m)) { s = m; }
        else { e = m; }
    }

    cout << max(f(s), f(s + 1)) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}