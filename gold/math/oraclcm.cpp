#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //this is weird because for some prime power, it has to be apparent in n - 1 elements
    //so calculate for each prime power, the amount that it appears as a factor in the hting
    //let's just sieve bruh i dont like this
    int N; cin >> N;
    vector<int> appear(200001);
    vector<int> sieve(200001);
    for (int i = 2; i <= 200000; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= 200000; j += i) {
            sieve[j] = i;
        }
    }
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        while (x > 1) {
            int p = sieve[x];
            int yes = p;
            while (x % p == 0) { x /= p; appear[yes]++; yes *= p; }
        }
    }
    long ans = 1;
    for (int i = 2; i <= 200000; i++) {
        if (sieve[i] != i || appear[i] < N - 1) { continue; }
        int oi = i;
        while (i * oi <= 200000 && appear[i * oi] >= N - 1) { i *= oi; }
        ans *= i;
        i = oi;
    }
    cout << ans << "\n";
}