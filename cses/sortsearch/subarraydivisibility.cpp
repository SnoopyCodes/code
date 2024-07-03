#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    map<int, int> m;
    m[0]++;
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cur += v[i];
        ans += m[((cur % N) + N) % N];
        m[((cur % N) + N) % N]++;
    }
    cout << ans << "\n";
    //
}