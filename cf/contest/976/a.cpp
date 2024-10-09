#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    int cnt = 0;
    int pow = K;
    if (K == 1) { cout << N << "\n"; return; }
    while ((long long) K * pow <= N) { K *= pow; }
    while (K > N) { K /= pow; }

    while (N > 0) {
        int remove = N / K;
        cnt += remove;
        N %= K;
        while (K > N) { K /= pow; }
    }
    cout << cnt << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}