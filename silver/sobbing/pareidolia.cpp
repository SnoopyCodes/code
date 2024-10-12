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
    ll ans = 0;
    int cnt = 0;
    vector<int> stages(5);
    for (int i = 0; i < N; i++) {
        int newb = 0;
        if (s[i] == 'b') {
            stages[0]++;
        }
        else if (s[i] == 'e') { newb += stages[4]; stages[4] = 0; stages[1] += stages[0]; stages[0] = 0; }
        else if (s[i] == 's') { stages[3] += stages[2]; stages[2] = stages[1]; stages[1] = 0; }
        else if (s[i] == 'i') { stages[4] += stages[3]; stages[3] = 0; }
        ans += newb * (N - i);
    }
    cout << ans << "\n";
}