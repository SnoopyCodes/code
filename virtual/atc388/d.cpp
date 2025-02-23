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
    vec<int> diff(N);  //amount decrease after time i
    int rate = 0;  //rate of increase
    rep(i, N) {
        int x; cin >> x;
        x += rate;
        rate++;
        if (x >= N - i - 1) {
            cout << x - (N - i - 1) << " ";
        }   else {
            diff[i + x]++;
            cout << 0 << " ";
        }
        rate -= diff[i];
    }
}