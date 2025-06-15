#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

#define long long long

const int MOD = 1e9 + 7;
const long INF = 4e18;

void solve() {
    int N; cin >> N;
    bool *A = new bool[N];
    A[0] = 1; //assume true.
    for (int i = 0; i < N - 1; i++) {
        cout << "? " << i + 1 << " " << i + 2 << "\n";
        cout.flush();
        int res; cin >> res;
        if (A[i]) { A[i + 1] = res; }
        else { A[i + 1] = !res; }
    }
    int s = 0, e = N;
    //find the leftmost point it differs at
    bool f = false;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        cout << "? " << 1 << " " << m + 1 << "\n";
        cout.flush();
        int res; cin >> res;
        if (res == A[m]) { s = m; }
        else { e = m; f = true; }
    }
    if (!f) {
        cout << "? 1 2" << "\n";
        cout.flush();
        int r1; cin >> r1;
        cout << "? 2 1" << "\n";
        cout.flush();
        int r2; cin >> r2;
        if (r1 == r2) { cout << "! " << N << "\n"; }
        else { cout << "! " << 1 << "\n"; }
        
    }
    else { cout << "! " << e << "\n"; }
    cout.flush();
}

int main() {
    int T; cin >> T; while(T--) { solve(); }
}