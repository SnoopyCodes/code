#include <bits/stdc++.h>

using namespace std;
int arr[1000][1000];  //default val 0 is wall. 1 is open 2 is target
int n, m;
string flood(int r, int c) {
    if (arr[r][c] == 0) { return "no"; }
    if (arr[r][c] == 2) { return ""; }
    arr[r][c] = 0;  //do not come back here
    string most = "no";
    string cur = "";
    if (r + 1 != n) {
        most = flood(r+1, c);
        if (most.compare("no") != 0) {
            most = "D" + most;
        }
    }
    if (r - 1 != -1) {
        cur = flood(r-1, c);
        if (cur.compare("no") != 0) {
            cur = "U" + cur;
            if (most.compare("no") == 0 || most.length() > cur.length()) { most = cur; }
        }
    }
    if (c + 1 != m) {
        cur = flood(r, c+1);
        if (cur.compare("no") != 0) {
            cur = "R" + cur;
            if (most.compare("no") == 0 || most.length() > cur.length()) { most = cur; }
        }
    }
    if (c - 1 != -1) {
        cur = flood(r, c-1);
        if (cur.compare("no") != 0) {
            cur = "L" + cur;
            if (most.compare("no") == 0 || most.length() > cur.length()) { most = cur; }
        }
    }
    arr[r][c] = 1;  //so you can come back here again :D
    return most;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    int sr, sc;
    for (int i = 0; i< n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == '.') { arr[i][j] = 1; }
            else if (str[j] == 'B') { arr[i][j] = 2; }
            else if (str[j] == 'A') { arr[i][j] = 1; sr = i; sc = j; }
        }
    }
    string ans = flood(sr, sc);
    if (ans.compare("no") == 0) { cout << "NO" << "\n"; }
    else {
        cout << "YES" << "\n";
        cout << ans.length() << "\n";
        cout << ans << "\n";
    }
}