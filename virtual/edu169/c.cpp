#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    //clearly, the optimal solution is 
    //alice takes largest, bob second, etc.
    //this is a very easy c
    //greedily increase while possible
    //suppose we have very many K
    //there is no way to get rid of the last
    vec<int> item(N);
    for (int i = 0; i < N; i++) {
        cin >> item[i];
    }
    sort(item.begin(), item.end());
    reverse(item.begin(), item.end());
    long diff = 0;
    for (int i = 0; i + 1 < N; i += 2) {
        int inc = min(item[i] - item[i+1], K);
        item[i+1] += inc;
        K -= inc;
        diff += item[i] - item[i+1];
    }
    if (N % 2 == 1) { diff += item[N - 1]; }
    cout << diff << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}