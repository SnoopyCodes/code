#include <bits/stdc++.h>

using namespace std;

#define long long long
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

void solve() {
    int N, K; cin >> N >> K;
    //at layer x the length is N >> x
    long ans = 0;
    int nseg = 1;
    int og = N;
    int between = 0;
    for (int b = 0; b < 32; b++) {
        int len = N;
        int add = N & 1;

        //all the #s that have suffix 1 << b, add here?
        if (len < K) {
            break;
        }
        if (add) {
            int fst = len + 1 >> 1;
            // cout << fst << " "  << og - fst << " " << nseg << "\n";
            //arithmetic sequence with fst = a, len = d, nseg terms
            ans += (fst + (long) (og - fst + 1)) * nseg / 2;
        }


        between = !add;
        nseg <<= 1;
        N >>= 1;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}