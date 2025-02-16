#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    //10101
    //

    //1
    //0101

    //
    //01011

    //1011
    //0
    //
    //move the furthest 1 over
    //and back
    int ans = 0;
    bool switched = false;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1' && !switched) { ans++; switched = true; }
        else if (s[i] == '0' && switched) { ans++; switched = false; }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}