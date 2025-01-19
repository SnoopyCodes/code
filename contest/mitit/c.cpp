#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        p[i] = x + y;
    }
    //eh just try greedy
    //x[i] + y[i] - x[j] - y[j]
    //compute x[i] + y[i] for each city
    //2, 0 to 0, 2 it takes like
    //0, -2, 3, 2, -1
    //2 + 5 + 1 + 3 + 1
    //-2, -1, 0, 2, 3
    //1 + 1 + 2 + 1 + 5
    //magically works?
    //0 5 7
    sort(p.begin(), p.end());
    long ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += (long) p[i+1] - p[i];
    }
    cout << ans + (long) p[N - 1] - p[0] << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}