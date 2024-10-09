#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    string s; cin >> s;
    //so we can only turn on i and i+1
    //once something has been turned on it cannot be turned off again
    //so we directly turn it into on?
    //when are things impossible to turn on?
    //odd number of things to turn on
    //
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] - '0') { cnt++; }
    }
    int m1 = -1, m2 = -1;
    if (cnt == 2) {
        for (int i = 0; i < N; i++) {
            if (s[i] - '0' && m1 == -1) { m1 = i; }
            else if (s[i] - '0' && m2 == -1) { m2 = i; }
        }
    }
    if (cnt % 2 != 0 || (m2 - m1 <= 1 && cnt == 2)) { cout << "NO" << "\n"; return; }
    else { cout << "YES" << "\n";}
    //now what
    //use 2 pointers from either side
    //wait is that it
    //because otherwise unless its 11 then 
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}