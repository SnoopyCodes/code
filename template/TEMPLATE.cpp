#include <bits/stdc++.h>
//i have
#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=(s);x!=(e);(s)<(e)?x++:x--)
#define rep2(x,e) rep3(x,(e)>0?0:-(e)-1,(e)>0?(e):-1)

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

//this is (not) fine
#define que queue
#define stk stack
#define pq priority_queue
#define rsz resize

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    rep(i, -(N-1)) {
        cout << i << "\n";
    }
    vec<int> a(100);
    set<int> x; x.insert(2);
    x.insert(3);
}