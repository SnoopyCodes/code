#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

vt<int> sieve;
vector<int> lin_sieve(int n) {
    sieve.resize(n + 1);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            sieve[i] = i;
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            sieve[i * primes[j]] = primes[j];
            if (primes[j] == sieve[i]) { break; }
        }
    }
    return primes;
}

vt<int> primes = lin_sieve(1e7);

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }
    ranges::sort(A);
    long long sum = 0;
    rep(i, 0, N) {
        sum += A[i] - primes[i];
    }
    int ans = 0;
    int tp = N - 1;
    while (sum < 0) {
        sum += primes[tp] - A[N - 1 - tp];
        tp--;
        ans++;
    }
    cout << ans << "\n";
    /*
    we always want to match them up with a prime.
    if we remove an element, we gain 
    largest difference between element and its prime
    
    */
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}