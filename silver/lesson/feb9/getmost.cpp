#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int num_fac(int K) {
    int num = 1;
    //just don't even sieve im lazy
    for (int i = 2; i * i <= K; i++) {
        if (K % i != 0) { continue; }
        int cnt = 0;
        while (K % i == 0) { K /= i; cnt++; }
        num *= cnt;
    }
    if (K != 1) { num *= 2; }
    return num;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int best = 1;
    for (int i = 50 * 64 - 50; i <= 50 * 64; i++) {
        if (i * num_fac(i) > i * num_fac(best)) { best = i; }
    }
    cout << best << " " << num_fac(best) << "\n";
}