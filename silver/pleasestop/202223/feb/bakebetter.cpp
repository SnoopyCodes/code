#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N, C, M; cin >> N >> C >> M;
    vector<array<long, 3>> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i][0] >> F[i][1] >> F[i][2];
    }
    int s = -1, e = C + M - 2;
    while (s + 1 < e) {
        int spend = s + (e - s) / 2;
        long least = max(1, C - spend), most = min(C, C - (spend - (M - 1)));
        for (auto const& [c, m, t] : F) {
            long rhs = m * M - m * spend + m * C - t;
            if (c - m == 0) {
                if (rhs > 0) { least = most + 1; }
            }   else if (c < m) {
                least = max(least, (rhs - 1) / (m - c) + 1);
            }   else {
                most = min(most, rhs / (m - c));
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