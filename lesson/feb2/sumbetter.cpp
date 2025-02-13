#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("in.txt", "r", stdin);
    int N; cin >> N;
    vector<int> A(N);
    vector<queue<int>> qs(1e6 + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        qs[A[i]].push(i);
    }
    for (int i = 1; i <= 1e6; i++) {
        qs[i].push(N);
    }
    long ans = (long) -N * (N + 1) / 2;
    map<int, int> last;
    for (int i = 0; i < N; i++) {
        qs[A[i]].pop();
        int l;
        int r = min(qs[A[i] + 1].front(), qs[A[i]].front());
        if (!last.count(A[i] + 1)) {
            l = -1;
        }   else {
            l = last[A[i] + 1];
        }
        ans += (long) (i - l) * (r - i);
        last[A[i]] = i;
    }
    cout << ans % MOD << "\n";
}