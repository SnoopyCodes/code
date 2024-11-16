#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int most = 1e6+1;
    vector<bool> sieve(most);
    for (int p = 2; p < most; p++) {
        if (sieve[p]) { continue; }
        for (int i = 2 * p; i < most; i += p) {
            sieve[i] = false;
        }
    }
    //yeah we can sieve this
    //but now what
    //we can say for some primes that these numbers are divided by it
    //and then?
    //then what
    // 
}