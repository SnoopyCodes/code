#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int odd = -(s.size() % 2 == 1);
    vector<int> freq(26);
    for (int i = 0; i < s.size(); i++) {
        freq[(int)(s[i] - 'A')]++;
    }
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] % 2 == 1 && (!odd || odd != -1)) { cout << "NO SOLUTION"; return 0; }
        else if (freq[i] % 2 == 1) {
            odd = i;
        }
    }
    for (int i = 0; i < freq.size(); i++) {
        for (int j = 0; j < freq[i] / 2; j++) {
            cout << (char) ('A' + i);
        }
    }
    if (odd || freq[0] % 2) { cout << (char) ('A' + odd); }
    for (int i = freq.size() - 1; i >= 0; i--) {
        for (int j = 0; j < freq[i] / 2; j++) {
            cout << (char) ('A' + i);
        }
    }
}