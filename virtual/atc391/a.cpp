#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    map<char, char> opp;
    opp['N'] = 'S';
    opp['S'] = 'N';
    opp['E'] = 'W';
    opp['W'] = 'E';
    string ans = "";
    string D; cin >> D;
    for (char c : D) {
        ans += opp[c];
    }
    cout << ans << "\n";
}