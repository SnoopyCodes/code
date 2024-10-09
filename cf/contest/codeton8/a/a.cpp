#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    if (K != 1 && K != N) { cout << -1 << "\n"; }
    else if (K == 1) {
        cout << 1 << " ";
        for (int i = 1; i < N; i++) {
            cout << 2;
            if (i != N-1) { cout << " "; }
        }
        cout << "\n";
    }   else if (K == N) {
        for (int i = 0; i < N; i++) {
            cout << 1;
            if (i != N-1) { cout << " "; }
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
    
}