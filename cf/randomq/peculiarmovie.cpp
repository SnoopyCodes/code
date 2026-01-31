#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    /*
    try not think advanced string stuff
    if there is ever a string of two consecutive chars then ez
    same with if length 1.
    */

    vt<string> strings(N);
    bool prec_done = false;
    set<string> s;
    map<string, vt<int>> occ;
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
        if (strings[i].size() == 1 || strings[i].size() == 2 && strings[i][0] == strings[i][1]) {
            prec_done = true;
        }
        s.insert(strings[i]);
        occ[strings[i]].add(i);
        ranges::reverse(strings[i]);
        if (s.count(strings[i])) {
            prec_done = true;
        }
        ranges::reverse(strings[i]);
    }
    if (prec_done) {
        cout << "YES" << "\n";
        return;
    }
    //consider ab if it is at start we want to match it to ba
    //actually, if we can find any matching 2 or 3 together
    //then it is always legal

    /*
    okay now what
    this means we have to find a sequence of matching 2s and 3s
    greedily match crap from the back?
    its some amount of 2s and 3s on the left side
    ab-cd-ef fed-cba
    ab-cde ed-cba
    we can compute # of prefixes and suffixes of 2s and 3s that have stuff
    should the lengths of the palindromes be short?

    ab-cd-efg gf-de-cba
    not necessarily??
    there are only 26^2 distinct 2-lengths they can give.

    oh
    ab-cba also works.. sample solving:
    bruh :skull: that was a lot easier than i thought.
    for each 2-string find the 3-strings it matches with.
    */

    bool can = false;
    for (auto [ss, v] : occ) {
        if (ss.size() == 3) { continue; }
        //consider this as left side
        int fst = v[0];
        int lst = v.back();
        for (char c = 'a'; c <= 'z'; c++) { //he said the thing
            string fstring = "";
            fstring.add(c), fstring.add(ss[1]), fstring.add(ss[0]);
            string lstring = "";
            lstring.add(ss[1]), lstring.add(ss[0]), lstring.add(c);
            if (occ.count(fstring) && occ[fstring].back() > fst) {
                can = true;
                break;
            }   else if (occ.count(lstring) && occ[lstring][0] < lst) {
                can = true;
                break;
            }
        }
    }

    if (can) { cout << "YES" << "\n";}
    else { cout << "NO" << "\n";}
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}