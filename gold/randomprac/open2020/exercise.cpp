#include <bits/stdc++.h>
#define long int64_t
using namespace std;

#define add(x, y) (((x) % MOD + (y) % MOD) % MOD + MOD) % MOD
#define mul(x, y) (((x) % MOD * (y) % MOD) % MOD + MOD) % MOD

int MOD;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    int N; cin >> N >> MOD;
    //and then i realized... math.
    //1: 1
    //2: 1 2 -> 1 2
    //2 1

    //0 1 -> 1 0 -> 0 1 so 2
    //answer for 2 is 3
    //this is like modulo circle forming

    //find all sets {x1, x2, x3...} where x1 + x2 ... = N
    //and all x >= 1, and all coprime
    //and find x1 * x2 ...

    //try a different approahc
    //oh shoot we need to not cover that which we have covered
    //like we essentially have it but we need to be careful
    //find largest power of something in something

    vector<bool> sieve(N + 1);
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= N; j += i) {
                sieve[j] = true;
            }
        }
    }
    vector<long> dp(N + 1, 1);  //this needs to be the answer..

    //first define dp: dp is the sum of all its partitions with coprime numbers..?
    //uhh no it is the sum of all its partitions with coprime numbers
    //then do we initialize everything to 1?
    //subtask 1 is possible but idk about 2
    //is sqrt log legal?
    //everything is stuck together and this is bad
    for (int p : primes) {
        for (int i = N; i >= p; i--) {
            int huh = p;
            while (huh <= i) {
                dp[i] = add(dp[i], mul(dp[i - huh], huh));
                huh *= p;
            }
        }
    }

    cout << dp[N] << "\n";
}