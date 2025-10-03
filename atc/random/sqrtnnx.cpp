#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    long X; cin >> X;
    vt<long> ans;
    long lim = sqrtl(abs(X + 1)) + 1e7 + 5;
    for (long M = sqrtl(abs(X + 1)) - 1; M <= lim; M++) {
        long M_sq = M * M;
        long target = M_sq - X;
        if (target < 0) { continue; }
        //BS
        long s = 0, e = abs(X) + 1;
        while (s + 1 < e) {
            long m = (s + e) / 2;
            if (m * m + m <= target) { s = m; }
            else { e = m; }
        }
        if (s * s + s == target) {
            ans.add(s);
        }
    }
    
    {
        vt<long> extra;
        for (long N : ans) {
            extra.add(-N - 1);
        }
        for (long N : extra) {
            ans.add(N);
        }
    }


    ranges::sort(ans);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}