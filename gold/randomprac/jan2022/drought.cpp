#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //first figure out what makes a n-tuple possible
    //clearly the bordering ones have to be <= the central ones?
    //same nonnegative hunger level
    //N even, N odd case?
    //if N even, we can aim for basically any hunger level
    //otherwise we have to aim for some particular level modulo 2
    //so we can say we're aiming for "0" or "1". set a suitable target level.
    //i keep saying suitable
    //so now we can say for each i we need to reduce it by x.
    //going by the above bordering <= center ones, we can calculate this?
    //i will submit subtask to check for correctness
    //example [8,10, 5]
    //if we head for 1, we get [1, -1, 1] and then if we head for 3 we get [3, 3, 3] ?
    //
    //eh... iterating over all possibilities is bad clearly
    //
    //wait solve for even N first.
    //what makes it possible for a thing to be solved?
    //a_0 <= a_1
    //a_1 - a_0 <= a_2
    //...
    //there exists a level l : sum of (even indices - l) = sum of (odd indices - l)?
    //is this all that is required? i think it has to satify inequalities on prefixes and
    //suffixes as well
    //for even N, it doesn't really matter what level we go for; we can go for 0
    //pref\suff
    //we need to formalize the condition further
    //wait. i believe it is just for odd i, sum of a_i >= sum of a_i across even i
    //and vice versa? does satisfying this condition across prefixes and also that 
    //total sum of both are equal satisfy the suffix? 
    //construct a test case against it.
    //proof by i cant do anything else, so this is possible.
    //okay, then

    //how to solution?
    //for even n, just use the given values, dp on difference of stuff
    //H^2N is ok!
    //for odd n, ruh ruh ruhr uhr oh
    //N^2 H^2 -> subtask 2?
    //how does one simplify it?
    //
    //H^2N is naively without a prefix sum? lets just solve even N
    int N; cin >> N;
    vt<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }


    auto solve = [&](vt<int> a) {
        int M = 1001;
        vt<vt<int>> dp(N, vt<int>(M, 0));
        rep(i, 0, a[0] + 1) dp[0][i] = 1;
        rep(i, 1, N) {
            //optimize with prefix sums.
            vt<int> pfs(M + 1);
            rep(j, 0, a[i] + 1) {
                pfs[j + 1] = (pfs[j] + dp[i-1][j]) % MOD;
            }
            rep(j, 0, a[i] + 1) {
                //j := A[i] - k
                dp[i][j] = pfs[a[i] - j + 1];
                //[0, a[i] - j]
            }
        }
        return dp[N-1][0];
    };

    if (N % 2 == 0) cout << solve(A) << "\n";
    else {
        int maxrem = *min_element(begin(A), end(A));
        int ans = 0;
        rep(base, 0, maxrem + 1) {
            vt<int> a = A;
            rep(i, 0, N) a[i] -= base;
            (ans += solve(a)) %= MOD;
        }

        cout << ans << "\n";
    }
    //time to play
    //how do we solve for odd N? we know that we have to have that condition
    //but in this case, the sum of differing parities of indices do not have to equate
    //is this the only condition?i mean just try it sure why not
    //it is not the only condition.
    //we know that we have to select a specific "level" for each
    //so by using prefix sums, we can do this?
}