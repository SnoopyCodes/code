#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N; cin >> N;
    //wait wtf
    //oh so its <= 1e6
    vector<bool> sieve(1e6+1);
    vector<int> primes;
    ll total = 0;
    for (int i = 2; i <= 1e6; i++) {
        if (sieve[i]) { continue; }
        for (int j = i * 2; j <= 1e6; j += i) {
            sieve[j] = true;
        }
        ll yeet = N / ((ll)i * i * i);  //primes up to this value work
        if (yeet < 2) { break; }
        //find first value larger than it
        int s = -1, e = primes.size();
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (primes[m] <= yeet) {
                s = m;
            }   else {
                e = m;
            }
        }
        total += e;
        primes.push_back(i);
    }
    cout << total << "\n";
}