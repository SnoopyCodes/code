#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    long ans = 1e18;
    long sum = 0;
    long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        total += A[i];
        if (i >= N / 2) {
            ans = min(sum, ans);
            sum -= A[i - N / 2];
        }
    }
    cout << ans << " " << total - ans << "\n";
}

int main() {
    int T; cin >> T; while(T--) { solve(); }
}