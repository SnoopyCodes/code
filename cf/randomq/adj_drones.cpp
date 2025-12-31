#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for(auto i=a; i<(b); i++)

void solve() {
    int N, K; cin >> N >> K;

    vt<int> app(3 * N);
    rep(i, 0, N) {
        int x; cin >> x; x--;
        app[x]++;
    }

    int cur = 0; //cur # of same drones?
    int ops = 0; //cur # of ops
    int ans = 0;

    /*
    we leave one at current location, keep moving forwards
    how do we simulate this process quickly?
    if we meet with another stack, how do we deal with it?

    current 5, new 3, k = 1
    its just sum up with next?
    */

    rep(i, 0, 3 * N) {
        cur += app[i];
        if (cur <= K) {
            cur = 0;
            ans = max(ans, ops);
            ops = 0;
        }   else {
            ops++;
            cur--;
        }
    }

    cout << ans << "\n";
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}