#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    vector<int> dp(N);
    map<array<int, 2>, int> m;
    int dc = 0, kc = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'K') { kc++; }
        else { dc++; }
        int sd = dc, sk = kc;
        int cd = gcd(sd, sk);
        sd /= cd, sk /= cd;
        m[{sd, sk}]++;
        cout << m[{sd, sk}] << " \n"[i == N - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //okay chill out bruh what
    //make many cuts, have the ratio all be the same
    //bruh
    //this is slightly hard
    int T; cin >> T; while(T--) { solve(); }
}