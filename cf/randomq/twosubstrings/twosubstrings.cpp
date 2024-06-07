#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<bool> used(s.size());
    int ab = 0, ba = 0;
    for (int i = 0; i < s.size()-1; i++) {  //check ab before ba
        if (s[i] == 'A' && s[i+1] == 'B') { ab++; used[i] = true, used[i+1] = true; }
        if (((ab && !used[i] && !used[i+1]) || (ab > 1)) && s[i] == 'B' && s[i+1] == 'A') { ba = true; }
    }
    if (ab && ba) { cout << "YES"; return 0; }
    ab = false, ba = false;
    used.clear(); used.resize(s.size());
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == 'B' && s[i+1] == 'A') { ba++; used[i] = true, used[i+1] = true; }
        if (((ba && !used[i] && !used[i+1]) || ba > 1) && s[i] == 'A' && s[i+1] == 'B') { ab = true; }
    }
    if (ab && ba) { cout << "YES"; }
    else { cout << "NO"; }
}