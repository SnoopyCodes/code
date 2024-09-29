#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    int cnt = 0;
    int pow = K;
    while (K * pow <= N && pow != 1) { K *= pow; }
    while (K > N) { K /= pow; }
    while (N > 0) {
        N -= K;
        cnt++;
        while (K > N && pow != 1) { K /= pow; }
    }
    cout << cnt << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}