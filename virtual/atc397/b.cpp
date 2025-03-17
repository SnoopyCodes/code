#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    //figure out if we need to add some stuff in front of this character
    int add = 0;
    rep(i, N) {
        int ind = add + i;
        if (ind % 2 == 0 && s[i] == 'o') { add++; }
        else if (ind % 2 == 1 && s[i] == 'i') { add++; }
    }
    if ((add + N) % 2 == 1) { add++; }
    cout << add << "\n";
}