#include <bits/stdc++.h>
#define long int64_t
using namespace std;

long fdiv(long n, long d) {
    long q = n / d, r = n % d;
    if (r != 0 && ((n < 0) != (d < 0))) { q--; }
    return q;
}

long cdiv(long n, long d) {
    long r = n % d;
    return fdiv(n, d) + (r != 0);
}

void solve() {
    int N, C, M; cin >> N >> C >> M;
    vector<array<long, 3>> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i][0] >> F[i][1] >> F[i][2];
    }
    int s = -1, e = C + M - 2;
    while (s + 1 < e) {
        int spend = s + (e - s) / 2;
        //find how many we spend on C
        long least = max(0, spend - (M - 1)), most = min(C - 1, spend);
        for (auto const& [c, m, t] : F) {
            long lhs = c * C + m * M - m * spend - t;
            if (c - m == 0) {
                if (lhs > 0) { least = most + 1; }
            }   else if (c > m) {
                least = max(least, cdiv(lhs, (c - m)));
            }   else {  //this is literally brain dead
                most = min(most, fdiv(lhs, (c - m)));
            }
        }
        if (least <= most) { e = spend; }
        else { s = spend; }
    }
    cout << e << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}