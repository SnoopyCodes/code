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
    int N, Q; cin >> N >> Q;
    string s, f; cin >> s >> f;
    vt<ii<2>> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q][0] >> queries[q][1];
        queries[q][0]--; queries[q][1]--;
    }
    //go the other way.
    //start with f. we can then edit < half of them
    //in this range thing before inspection
    //let's say we do do our lazy range set and whatnot
    //aren't all our actions forced then?
    //yeah.
    //so is the gap literally just
    //a lazy segtree?
    //no we can do simpler
    //compress it into ranges actually
    //and yea that'll work.
    set<ii<3>> cur;
    for (int i = 0; i < N; i++) {
        int j = i + 1;
        while (j < N && f[j] == f[i]) { j++; }
        cur.insert({ i, j - 1, f[i] == '1' ? 1 : -1});
        i = j - 1;
    }
    bool can = true;
    while (Q--) {
        auto [l, r] = queries[Q];
        //get the segment containing the point i: 
        //find the first one > for sure, then --.
        auto first = --cur.upper_bound({ l, N, 0 });
        if ((*first)[0] != l) {
            auto [a, b, t] = *first;
            cur.erase(first);
            cur.insert({ a, l - 1, t });
            cur.insert({ l, b, /*g*/ t });
        }

        auto last = --cur.upper_bound({ r, N, 0 });
        if ((*last)[1] != r) {
            auto [a, b, t] = *last;
            cur.erase(last);
            cur.insert({ a, r, t });
            cur.insert({ r + 1, b, t });
        }

        first = --cur.upper_bound({ l, N, 0 });
        last = cur.upper_bound({ r, N, 0 });

        int sum = 0;
        for (auto it = first; it != last; it = cur.erase(it)) {
            auto [a, b, t] = *it;
            sum += (b - a + 1) * t;
        }
    }
    string res = "";
    for (auto [a, b, t] : cur) {
        for (int i = 0; i < b - a + 1; i++) {
            char c = t > 0 ? '1' : '0';
            res += c;
        }
    }
    if (res == s && can) {
        cout << "YES" << "\n";
    }   else {
        cout << "NO" << "\n";
    }


}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}