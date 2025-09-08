#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

void solve() {
    string s; cin >> s;
    int N = s.size();
    //segtroll
    vt<int> c(N);
    vt<int> occ;
    for (int i = 0; i < N; i++) {
        if (s[i] == '(') { c[i] = +1; }
        else if (s[i] == ')') { c[i] = -1; }
        else { occ.add(i); }
    }
    //obviously, prefix sum at all times must be >= 0
    //set all of them to +1, and then convert the last few into -1 so it balances
    //then try switching the two in between.
    //if theres a consecutive string of 3 ? then its always doable? incorrect
    //find consecutive segments where it hits 0.
    //
    int cur = accumulate(c.begin(), c.end(), 0) + occ.size();
    int last_change = occ.size() - 1;
    while (cur != 0) {
        cur -= 2;
        last_change--;
    }
    if (last_change == -1 || last_change == occ.size() - 1) {
        cout << "YES" << "\n";
        return;
    }
    bool ok = true;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (!c[i]) {
            if (i < occ[last_change]) { c[i] = +1; }
            else if (i == occ[last_change + 1]) { c[i] = +1; }
            else { c[i] = -1; }
        }
        sum += c[i];
        ok &= sum >= 0;
    }
    if (!ok) {
        cout << "YES" << "\n";
    }   else {
        cout << "NO" << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}