#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    map<int, int> m;
    vector<int> divs(2e5 + 1);  //LIS
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        m[k]++;
    }
    //this simplifies the problem greatly!
    //if A[i] > A[i-1], then A[i-1] | A[i], must happen
    //therefore the problem becomes: find the LIS
    //such that all elements divide it
    int most_div = 0;
    for (auto [e, f] : m) {
        most_div = max(most_div, divs[e] + f);
        for (int i = 2 * e; i < 2e5 + 1; i += e) {
            divs[i] = max(divs[i], f + divs[e]);
        }
        
    }
    cout << N - most_div << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}