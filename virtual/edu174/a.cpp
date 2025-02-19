#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,e>0?0:-(e)-1,e>0?e:-1)

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    vec<int> B(N);
    for(int i = 0; i < N - 2; i++) cin >> B[i+1];
    //just greedily fill it
    //wait chill what
    vec<int> A(N);
    bool ok = true;
    int lst = -10;
    for (int i = 1; i < N - 1; i++) {
        if (B[i]) {
            if (i - lst == 2) { ok = false; }
            lst = i;
        }
    }
    if (ok) { cout << "YES" << "\n";}
    else { cout << "NO" << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}