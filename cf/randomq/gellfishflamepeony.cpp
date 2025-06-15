#include <bits/stdc++.h>

using namespace std;

vector<int> sieve;

void era(int n) {
    sieve.resize(n + 1);
    for (int i = 2; i <= n; i += 2) {
        sieve[i] = 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (sieve[i]) { continue; }
        sieve[i] = i;
        for (int j = i * i; j <= n; j += i) {
            sieve[j] = i;
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    int gg = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        gg = gcd(A[i], gg);
    }
    if (gg != 1) { cout << -1 << "\n"; return 0; }
    sort(A.begin(), A.end());
    unique(A.begin(), A.end());
    era(*max_element(A.begin(), A.end()));
    vector<vector<int>> prime_facs(N);
    //find primes.
    //the minimum size known is like
    //min prime factors + 1
    //we can in fact do bitmask dp for one of them
    //but isnt this not going to work
    //do we want the one with the least prime factors?
    //what shall we dp on?
    //if 1 exists, 1.
    //we want to find min ops such that subset of all of them lead to 1
    //map<int, int> dp? when should we erase an entry? the problem is with bitmasks
    //there are 300,000 ways to start off. how do we erase this?
    //well just choose 20 primes
    //extinguish any numbers that are multiples of any other numbers
    //
    for (int i = 0; i < N; i++) {
        
    }
}