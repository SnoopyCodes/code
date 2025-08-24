#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int N; cin >> N;
    vt<int> S(N);
    long ans = 0;
    vt<int> pf(N + 1);
    string ss; cin >> ss;
    for (int i = 0; i < N; i++) {
        S[i] = ss[i] == '1' ? 1 : -1;
        pf[i + 1] = pf[i] + S[i];
        ans += (long) (i + 1) * (N - i);
    }
    /*
    each substring can be described as a pair (# of 0s, # of 1s)
    and returns the max
    i would like a way to do range updates on this.
    then it is simple

    ok wait ik how to dnc

    oh so let a = #0 and b = #1
    a + b = len of segment
    calculate a - b, summing /2 yields a. i knew this, 
    but the key part is you can split it up.
    length of segment is easy
    |a - b| is the one we wish for
    calculate |a - b| over all segments, please
    use prefix sums. im getting rolled so hard
    damn good problem though.!
    */
    ranges::sort(pf);
    for (int i = 0; i < N + 1; i++) {
        ans += (long) pf[i] * (i) - (long) pf[i] * (N - i);
    }
    

    cout << ans / 2 << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}