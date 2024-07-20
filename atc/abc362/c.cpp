#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<array<int, 2>> bounds(N);
    vector<ll> lower(N+1);
    vector<ll> upper(N+1);
    for (int i = 0; i < N; i++) {
        cin >> bounds[i][0] >> bounds[i][1];
        lower[i+1] = lower[i] + bounds[i][0];
        upper[i+1] = upper[i] + bounds[i][1];
    }
    if (lower[N] > 0 || upper[N] < 0) { cout << "No" << "\n"; return 0; }
    cout << "Yes" << "\n";
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll r = upper[N] - upper[i+1];
        sum += bounds[i][0];
        if (sum + r < 0) {
            cout << 0 - (r + sum) + bounds[i][0];
            sum = -r;
        }   else {
            cout << bounds[i][0];
        }
        cout << " \n"[i == N - 1];
    }
}