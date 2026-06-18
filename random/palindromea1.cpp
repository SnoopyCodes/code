#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        string cur = "";
        for (int j = 0; j < N; j++) {
            if (s[j].size() >= i + 1) {
                cur += s[j][i];
            }
        }
        bool ok = true;
        for (int j = 0; j < cur.size() / 2; j++) {
            ok &= cur[j] == cur[(int) cur.size() - 1 - j];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}