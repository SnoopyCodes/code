#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, C, K; cin >> N >> C >> K;
    vt<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ranges::sort(A);
    for (int i = 0; i < N; i++) {
        if (C >= A[i]) {
            int d = C - A[i];
            int inc = min(K, d);
            C += A[i] + inc;
            K -= inc;
        }
    }
    cout << C << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}