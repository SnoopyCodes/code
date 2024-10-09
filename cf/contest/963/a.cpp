#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    string s; cin >> s;
    vector<int> cnt(4, N);
    int ans = 0;
    for (int i = 0; i < 4 * N; i++) {
        if (s[i] == 'A') {
            if (cnt[0] != 0) {
                cnt[0]--;
                ans++;
            }
        }   else if (s[i] == 'B') {
            if (cnt[1] != 0) {
                cnt[1]--;
                ans++;
            }
        }   else if (s[i] == 'C') {
            if (cnt[2] != 0) {
                cnt[2]--;
                ans++;
            }
        }   else if (s[i] == 'D') {
            if (cnt[3] != 0) {
                cnt[3]--;
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}