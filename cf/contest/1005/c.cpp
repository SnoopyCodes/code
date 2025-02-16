#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    vec<int> A(N);
    for (int i = 0; i  < N; i++) {
        cin >> A[i];
    }
    //max coins to have
    //oh if a[i] < 0
    //ok wow
    //inspect the two ends
    //just a simple dp will do?
    //one can go one way the other the other
    //calculate the sweep left and the sweep right
    vec<long> left(N), right(N);
    for (int i = 0; i < N; i++) {
            if (i > 0) { right[i] = right[i-1]; }
        if (A[i] > 0) {
            right[i] += A[i];
        }
            if (N - i - 1 < N - 1) { left[N - i - 1] = left[N - i]; }
        if (A[N - i - 1] < 0) {
            left[N - i - 1] -= A[N - i - 1];
        }
    }
    for (int i = 0; i < N; i++) {
        if (i > 0)  {
            right[i] = max(right[i], right[i-1]);
            left[N - i - 1] = max(left[N - i - 1], left[N - i]);
        }
    }
    long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, left[i] + right[i]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}