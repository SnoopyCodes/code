#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int N; cin >> N;
    //we can know the contribution of each one at every turn
    //we can have N^2
    vector<array<int, 2>> op(N);
    vector<array<int, 2>> type(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            char c; cin >> c;
            type[i][j] = c == 'x';
            cin >> op[i][j];
        }
    }
    //maybe we if back compute the maximum that anyone can adding one to either
    vector<array<i64, 2>> gain(N + 1, {1, 1});
    for (int i = N - 1; i > -1; i--) {
        i64 best = max(gain[i+1][0], gain[i+1][1]);
        for (int j = 0; j < 2; j++) {
            if (!type[i][j]) { gain[i][j] = gain[i+1][j]; }
            else {
                gain[i][j] = (op[i][j] - 1) * best + gain[i+1][j];
            }
        }
    }

    array<i64, 2> cur{1, 1};
    for (int i = 0; i < N; i++) {
        i64 inc = 0;
        for (int j = 0; j < 2; j++) {
            if (type[i][j]) { inc += op[i][j] * cur[j] - cur[j]; }
            else { inc += op[i][j]; }
        }
        if (gain[i+1][0] >= gain[i+1][1]) { cur[0] += inc; }
        else { cur[1] += inc; }
    }
    cout << cur[0] + cur[1] << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}