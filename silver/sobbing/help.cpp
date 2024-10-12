#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    //bessbiessie B value is only 1
    //but bessbie is 1, and biessie is 1
    //we could probably sliding window 
    //if we move right
    //
    //let cnt be number of completed ones we have rn
    //
    //do freaking N^2 then
    string b = "bessie";
    ll ans = 0;
    int prev = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        int j = 0;
        int stage = 0;
        while (j <= i) {
            if (s[j] == b[stage]) { stage++; }
            if (stage == 6) { stage = 0; cnt++; }
            j++;
        }
        //help help hlep help help help hlep hlep 
        //count stage
        ans += (cnt - prev) * (N - i);
        ans += prev;
        prev = cnt;
        //help help hlep help help hlpe hlep help hlep hlep hlep hlep help ehlpe hlpe
        //

    }
    cout << ans << "\n";
}