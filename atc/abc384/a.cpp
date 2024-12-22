#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    char c, r; cin >> c >> r;
    string s; cin >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] != c) { s[i] = r; }
    }
    cout << s << "\n";
}