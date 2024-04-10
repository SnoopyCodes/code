#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int longest = 0;
    for (int i = 0; i < s.size(); i++) {
        int len = 1;
        while (i+1 < s.size() && s[i] == s[i+1]) {
            len++;
            i++;
        }
        longest = max(longest, len);
    }
    cout << longest << "\n";
}