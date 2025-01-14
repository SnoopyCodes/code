#include <bits/stdc++.h>
#define long int64_t
using namespace std;

#define add(x, y) (((x) % MOD + (y) % MOD) % MOD + MOD) % MOD
#define mul(x, y) (((x) % MOD * (y) % MOD) % MOD + MOD) % MOD


int MOD;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N >> MOD;
    vector<int> p(N);
    int f = 1;
    for (int i = 0; i < N; i++) {
        p[i] = i;
        f *= i + 1;
    }
    int ans = 0;
    set<int> s;
    for (int i = 0; i < f; i++) {
        vector<bool> visited(N);
        int res = 1;
        for (int i = 0; i < N; i++) {
            if (visited[i]) { continue; }
            int dist = 1;
            visited[i] = true;
            int pos = p[i];
            while (pos != i) {
                visited[pos] = true;
                pos = p[pos];
                dist++;
            }
            res = lcm(res, dist);
        }
        s.insert(res);
        next_permutation(p.begin(), p.end());
    }
    for (int x : s) {
        ans += x;
    }
    cout << ans << "\n";
}