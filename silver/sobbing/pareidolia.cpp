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
    //to find B(s) naively we clearly do the process find letters of "bessie" then work on the substring of that
    //how do we do this for all substrings?
    //obviously, look at N^2
    //lets look at prefixes?
    //S(B(s)) = S(B(s-1)) + ?
    //? is the number of new "bessie" created by adding this, right?
    //treat each character as starting a dang thing
    //every character is starting its own greedy algorithm
    //
    ll ans = 0;
    vector<int> stages(6);
    for (int i = 0; i < N; i++) {
        stages[0]++;
        int cnt = 0;
        if (s[i] == 'b') {
            stages[1] += stages[0]; stages[0] = 0;
        }   else if (s[i] == 'e') {
            stages[2] += stages[1]; stages[1] = 0;
            cnt = stages[5]; stages[5] = 0;
        }   else if (s[i] == 's') {
            stages[4] += stages[3]; stages[3] = 0;
            stages[3] += stages[2]; stages[2] = 0;
        }   else if (s[i] == 'i') {
            stages[5] += stages[4]; stages[4] = 0;
        }
        stages[0] += cnt;
        ans += (ll)cnt * (N - i);
    }
    cout << ans << "\n";
}