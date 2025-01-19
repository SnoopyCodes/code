#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s1, s2; cin >> s1 >> s2;
    int N = s1.size();
    vector<bool> f(N), s(N);
    for (int i = 0; i < N; i++) {
        f[i] = s1[i] == 'B';
        s[i] = s2[i] == 'B';
    }
    vector<set<int>> vs(4);
    auto get_set = [&](bool z, int ind) {
        return z * 2 + ind % 2;
    };
    for (int i = 0; i < N; i++) {
        auto x = get_set(s[i], i);
        vs[x].insert(i);
    }
    bool yes = true;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto x = get_set(s[i], i);
        vs[x].erase(i);
        if (f[i] == s[i]) { continue; }
        auto y = get_set(f[i], i);
        if (vs[y].empty()) { yes = false; break; }
        int j = *vs[y].begin();
        int d = j - i;
        ans += d / 2;
        s[j] = !s[j];
        vs[y].erase(vs[y].begin());
        vs[x].insert(j);
    }
    if (!yes) { cout << -1 << "\n"; return; }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}