#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    string t; cin >> t;
    int N = s.size(), M = t.size();
    vt<int> freqs(26);
    for (char c : s) {
        freqs[c - 'a']++;
    }
    /*
    O(NM) is ok
    we can check if possible easily.
    just iterate on the length of the prefix we match, and match it?
    */

    string ck = s;
    ranges::sort(ck);
    ranges::reverse(ck);
    if (t >= ck) {
        cout << -1 << "\n";
        return 0;
    }
    auto finish = [&]() {
        string res = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freqs[i]; j++) {
                res += (char) (i + 'a');
            }
        }
        return res;
    };
    string pref = "";
    
    for (int i = 0; i <= M; i++) { //length of prefix that we will match.
        if (i == M) { //taken whole string, print it.
            string ans = pref + finish();
            cout << ans << "\n";
        }   else {
            //try matching this one.
            freqs[t[i] - 'a']--; //will be in prefix
            pref += t[i];
            string suff = finish();
            ranges::reverse(suff);
            if (pref + suff <= t || freqs[t[i] - 'a'] < 0) {
                //this is not ok.
                freqs[t[i] - 'a']++;
                pref.pop_back();
                for (int j = t[i] - 'a' + 1; j < 26; j++) {
                    if (freqs[j]) {
                        freqs[j]--;
                        cout << (pref + (char) (j + 'a') + finish()) << "\n";
                        return 0;
                    }
                }

            }   else {
                //do nothing??
            }
        }
    }
    
}