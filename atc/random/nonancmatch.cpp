#include <bits/stdc++.h>

using namespace std;

#define long long long
#define rep(i, a, b) for (auto i = a; i < (b); i++)
#define vt vector
#define vi vt<int>
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    vi P(N);
    vi depth_size(N);
    vi depth(N);
    depth_size[0] = 1;
    rep(i, 1, N) cin >> P[i], P[i]--, depth[i] = depth[P[i]] + 1, depth_size[depth[i]]++;

    int ans = 0;
    bool carry = false;
    for (int i = N - 1; i > -1; i--) {
        if (carry && depth_size[i] > 1) {
            ans++;
            depth_size[i]--;
        }
        ans += depth_size[i] / 2;
        carry |= depth_size[i] & 1;
        if (ans) cout << ans << "\n";
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int T; cin >> T; while (T --> 0) solve(); 
}