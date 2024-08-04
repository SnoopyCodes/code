#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int segsize = N % K; if (segsize == 0) { segsize += K; }
    int ops = N / K; if (segsize == K) { ops--; }
    
    //we need to dp 
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T) { T--; solve(); }
}