#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N, P; cin >> N >> P;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //dude im so bad
    vector<array<int, 2>> sorted(N);
    for (int i = 0; i < N; i++) {
        sorted[i][0] = v[i];
        sorted[i][1] = i;
    }
    sort(sorted.begin(), sorted.end());

    ll ans = 0;
    vector<bool> links(N - 1); //connects i and i + 1
    int linked = 0;
    for (int i = 0; i < N && sorted[i][0] < P; i++) {
        int j = sorted[i][1];
        int curgcd = sorted[i][0];
        for (int k = j - 1; k > -1; k--) {
            curgcd = gcd(curgcd, v[k]);
            if (curgcd != sorted[i][0] || links[k]) { break; }
            links[k] = true;
            ans += sorted[i][0];
            linked++;
        }
        curgcd = sorted[i][0];
        for (int k = j; k < N - 1; k++) {
            curgcd = gcd(curgcd, v[k+1]);
            if (curgcd != sorted[i][0] || links[k]) { break; }
            links[k] = true;
            ans += sorted[i][0];
            linked++;
        }
    }
    cout << ans + (ll)(N - 1 - linked) * P << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}