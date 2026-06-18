#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*
    guessing is fun
    criteria: each diagonal has the same #
    categorize diagonal by i + j
    */

    int N, M; cin >> N >> M;
    vt<map<int, int>> freqs(N + M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
            freqs[i + j][x]++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
            freqs[i + j][x]--;
            if (!freqs[i + j][x]) {
                freqs[i + j].erase(x);
            }
        }
    }

    int ok = 1;
    for (int i = 0; i < N + M; i++) ok &= freqs[i].empty();
    cout << (ok ? "YES" : "NO") << "\n";

}