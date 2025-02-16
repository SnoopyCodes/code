#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; i + 2 * j < N; j++) {
            if (s[i] == 'A' && s[i + j] == 'B' && s[i + 2 * j] == 'C') { ans++; }
        }
    }
    cout << ans << "\n";
}