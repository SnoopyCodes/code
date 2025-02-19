#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=(s);x!=(e);(s)<(e)?x++:x--)
#define rep2(x,e) rep3(x,e>0?0:-e-1,e>0?e:-1)

const int INF = 1e9;
const long INFL = 4e18;
const int MOD = 998244353;

using namespace std;

void solve() {
    int N; cin >> N;
    vec<int> A(N);
    rep(i, N) { cin >> A[i]; }
    //required: 1, 2, 2, 2, ..., 3
    //brute force is possible
    //but not required
    //each {1, 3} pair contributes to 2^(# of 2's in between) - 1
    //chat is this math
    //prefix sum array of 2s
    //in a 1 1 1 1 2 2 2 2 2 33 3 3 
    //each 3 is like 2^5 for each 1
    //so can we count for a 2 how much it doesn't work?
    //the problem with 1 3 pairs is that they keep extending.. give them dead spots?
    //we kind of need like a "count"
    //again can we count for 2's?
    //let it be the leftmost 2 in the subseq
    //well let "1" be "start" and 3 be "end"
    //for each start and end calculate 2^(pf[end] - pf[start])
    //too many starts, and too many ends...
    //group 2's together
    //welp dnc?
    //across a half.. things keep varying and idk how to track it
    //no binary search, no nothing
    //compression does nothing
    //wait chat i am stupid you just multiply by two no?
    //omg bruh like wehat what
    //1, 2, 3
    //0, 1, 1 (+1)
    //1, 2, 2, 3
    //gives 3, not 1
    int ans = 0;
    int wait = 0;
    int cur = 0;
    rep(i, N) {
        if (A[i] == 1) { wait++; }
        else if (A[i] == 2) {
            cur = (cur * 2) % MOD;
            cur += wait;
        }   else {
            ans = (ans + cur) % MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}