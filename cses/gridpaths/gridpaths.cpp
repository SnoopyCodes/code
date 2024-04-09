#include <bits/stdc++.h>

using namespace std;
//not in working order
string s;
bool visited[7][7];
int total = 0;
int paths(int r, int c, int step) {
    total++;
    if (r < 0 || c < 0 || r == 7 || c == 7 || visited[r][c]) { return 0; }
    if (step < 48 && r == 6 && c == 0) { return 0; }
    else if (step == 48 && r == 6 && c == 0) { return 1; }
    visited[r][c] = true;
    int ans;
    if (s[step] == '?') {
        ans = paths(r+1,c,step+1)+paths(r-1,c,step+1)+paths(r,c-1,step+1)+paths(r,c+1,step+1);
    }   else if (s[step] == 'U') {
        ans = paths(r-1, c, step+1);
    }   else if (s[step] == 'D') {
        ans = paths(r+1, c, step+1);
    }   else if (s[step] == 'R') {
        ans = paths(r, c+1, step+1);
    }   else {
        ans = paths(r, c-1, step+1);
    }
    visited[r][c] = false;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    cout << paths(0, 0, 0) << "\n";
    cout << total << "\n";
}