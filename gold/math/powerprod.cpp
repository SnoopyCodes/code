#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> A(N);
    map<int, long> m;
    long ans = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        int o = x;
        vector<array<int, 2>> primefac;
        for (int i = 2; i * i <= x; i++) {
            if (x % i) { continue; }
            int cnt = 0;
            while (x % i == 0) { x /= i; cnt++; }
            primefac.push_back({i, cnt % K});
        }
        if (x != 1) { primefac.push_back({x, 1}); }
        int cur = 1;
        bool valid = true;
        x = 1;
        for (auto [p, e] : primefac) {
            int oe = e;
            while (oe) { x *= p; oe--; }
            e = (K - e) % K;
            int op = p;
            p = 1;
            while (e > 0 && p <= 100000) { e--; p *= op; }
            if ((long) p * cur >= 100000) {
                valid = false;
            }
            cur *= p;
        }
        if (valid) {
            ans += m[cur];
        }
        m[x]++;
    }
    cout << ans << "\n";
    //2 3 5 7 11 13 17
    //so uh we can use a map
    //wait prime factorize every single one
    //and then afterwards we want to find pair sums to equal them to multiples of k
    //use a map
}