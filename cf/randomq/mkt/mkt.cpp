#include <bits/stdc++.h>

using namespace std;
//https://codeforces.com/contest/1418/problem/C
int N;
vector<bool> bosses;
vector<int> minme;
vector<int> minf;
void solve() {
    cin >> N;
    minf.clear();
    minf.resize(N+1, INT_MAX / 2);
    minme.clear();
    minme.resize(N+1, INT_MAX / 2);
    bosses.clear();
    bosses.resize(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        bosses[i] = x;
    }
    minf[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 <= N) {
            minf[i+1] = min(minme[i], minf[i+1]);
        }
        if (i+2 <= N) {
            minf[i+2] = min(minf[i+2], minme[i]);
        }

        //split friend
        if (bosses[i]) { minf[i]++; }
        if (i+1 <= N) {
            minme[i+1] = min(minme[i+1], minf[i]);
        }
        if (i+2 <= N) {
            minme[i+2] = min(minme[i+2], minf[i]+bosses[i+1]);
        }
    }
    cout << min(minme[N], minf[N]) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}