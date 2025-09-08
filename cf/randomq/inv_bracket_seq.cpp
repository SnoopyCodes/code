#include <bits/stdc++.h>

using namespace std;
#define EN(i, v) " \n"[i == v.size() - 1]
#define long long long
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array< int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    string ss; cin >> ss;
    int N = size(ss);
    vt<int> s(N);
    for (int i = 0; i < N; i++) {
        char c = ss[i];
        s[i] = c == '(' ? 1 : -1;
    }
    vt<int> pf(N), sf(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += s[i];
        pf[i] = sum;
    }
    sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        sum += s[i];
        sf[i] = sum;
    }
    //suppose we flip from l to r
    //sum to l - 1 must be >= sum of 
    //maximum prefix sum in [l, r]
    //so now it is easy to solve in N^2 log
    //we cannot swap across any zero points? incorrect.
    //we can only swap with range sum 0
    //and yea it has that condition of pref[0...l - 1] >= maxprefsum[l, r]
    //pref[0,r] = pref[0...l-1]
    //
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}