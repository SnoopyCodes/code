#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    if (size(s) % 2 == 1) {
        cout << "No" << "\n";
        return 0;
    }
    /*
    one condition is the other side must have + connected to top
    we can condense all the +++ rows and stuff
    if size(s) % 2 = 1 then no?
    then after condensing if the size is odd then yes?

    okay insane
    -+- -> ""
    unknot it step by step
    all sets of 3 disappear
    if one remains, is it guaranteed to be good?
    3 sets of 3 and 1?
    +-+ -+- +-+ -

    apparently not
    if a condense chain is length 3, it doesn't disappear.
    +++ -> +
    ++ -> ""
    
    is this the only modification?
    is our % 3 logic ok??
    */

    vt<char> condense;
    char prev = '.';
    int len = 0;
    for (char x : s) {
        if (x != prev) {
            if (len % 2 == 1) {
                if (!condense.empty() && condense.back() == prev) {
                    condense.pop_back();
                }   else {
                    condense.add(prev);
                }
            }
            prev = x;
            len = 1;
        }   else {
            len++;
        }
    }
    if (len % 2 == 1) {
        if (!condense.empty() && condense.back() == prev) {
            condense.pop_back();
        }   else {
            condense.add(prev);
        }
    }

    if (size(condense) < 2) {
        cout << "Yes" << "\n";
    }   else {
        cout << "No" << "\n";
    }
}