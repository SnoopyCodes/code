#include <bits/stdc++.h>
//modint my beloved
using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
using i64 = long long;

struct mi {
    static const int MOD = 1e9 + 7;
    int v;
    mi() : v(0) {}
	mi(i64 _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mi operator+(mi a, const mi& b) { return mi(a.v + b.v); }
	friend mi operator*(mi a, const mi& b) { return mi((i64)a.v*b.v); }
	mi& operator+=(const mi& o) { return (*this) = (*this) + o; }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vec<vec<mi>> ways(N + 1, vec<mi>(N));
    vec<vec<mi>> pre(N + 1, vec<mi>(N + 1));
    pre[0][0] = 1;
    rep(i, 1, N + 1) {
        pre[i][0] = 1;
        rep(j, 1, i + 1) {
            pre[i][j] = pre[i-1][j] + pre[i-1][j-1];
        }
    }
    rep(i, N) {
        ways[i+1][i] = 1;
    }

    for (int len = 2; len <= N; len += 2) {
        rep(i, N - len + 1) {
            for (int j = i + 1; j <= i + len - 1; j += 2) {
                //for range [i][i + len], consider finding j such that s[i] == s[j]
                //and adding these possibilities
                if (s[i] != s[j]) { continue; }
                //range: [i, j], and [j + 1, i + len - 1]
                //remove [i+1, j-1] and [j+1, i+len-1], and then this one
                //these 3 can be done in an order where this removal falls after [i+1, j-1]
                //total operations for this substring is len / 2.
                //choose some to go first: (j - i + 1) / 2
                mi between = ways[i+1][j-1];
                mi after = ways[j+1][i+len-1];
                ways[i][i + len - 1] += between * after * pre[len / 2][(j - i + 1) / 2];
            }
        }
    }
    cout << ways[0][N-1].v << "\n";
}