#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    cout << (N - 1) * K + 1 << "\n";    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T) { T--; solve(); }
}