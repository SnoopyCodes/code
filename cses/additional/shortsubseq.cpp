#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<char> chars = {'A', 'C', 'G', 'T'};
    int cur = 0;  //how many at the current one are set
    for (int i = 0; i < N; i++) {
        int x = 0;
        while (chars[x] != s[i]) { x++; }
        if ((cur | (1 << x)) == 15) {
            cout << chars[x];
            cur = 0;
        }   else {
            cur |= (1 << x);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!(cur & 1 << i)) {
            cout << chars[i];
            break;
        }
    }
}