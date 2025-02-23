#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const long INF = 4e18 + 7e9;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    //oh...
    //this feels like a subproblem from plat
    //just binary search
    int s = 0, e = N / 2 + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        //how do we form exactly m kagamimochi?
        //select the minimum k... and see if upper ones match up
        //hmm so WA
        //what why
        //only 3 wa our approach is correct!
        //oh multiset :skull:
        multiset<int> in;
        rep(i, m) {
            in.insert(A[i]);
        }
        rep(i, m, N) {
            if (in.empty()) { break; }
            if (*in.begin() * 2 <= A[i]) {
                in.erase(in.begin());
            }
        }
        if (in.empty()) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}