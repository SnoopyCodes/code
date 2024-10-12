#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 1; i < N - 1; i++) {
        if (s[i-1] == '#' && s[i+1] == '#' && s[i] == '.') { cnt++; }
    }
    cout << cnt << "\n";
}