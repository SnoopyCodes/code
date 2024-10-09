#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    int minmax = INT_MAX;
    int prev; cin >> prev;
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        minmax = min(minmax, max(prev, a));
        prev = a;
    }
    cout <<  minmax - 1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}