#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int sum; cin >> sum;
    long ans = 0;
    for (int i = 0; i < N && A[i] <= sum / 2; i++) {
        if (i > 0 && A[i] == sum / 2 && A[i-1] == A[i]) { break; }
        int s = 0, e = N;
        int diff = sum - A[i];
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (A[m] <= diff) { s = m; }
            else { e = m; }
        }
        ans += s - i;
    }
    cout << ans << "\n";
}