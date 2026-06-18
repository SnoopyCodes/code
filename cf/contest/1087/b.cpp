#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    /*
    think number line. 
    wait j > i
    distance from this is further than others.
    we can find # of < and # of >
    */

    for (int i = 0; i < N; i++) {
        int less = 0, greater = 0;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[i]) { less++; }
            else if (A[j] > A[i]) { greater++; }
        }
        cout << max(less, greater) << " \n"[i == N - 1];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}