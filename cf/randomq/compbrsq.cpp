#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for(auto i=a; i < (b); i++)

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<ll<2>> segs; //segment of each increasing whatever
    long h = 0;
    long ans = 0;
    vt<int> A(N);
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) {
        int k = A[i];
        long l = h - k;
        long r = h - 1;
        //forgot to maintain [l, r] through backtracking.
        if (i & 1) for (int i = size(segs) - 1; i > -1; i--) {
            auto [a, b] = segs[i];
            ans += max(0LL, min(r, b) - max(l, a) + 1);

            r = min(r, a);

            if (a < l) break;
            //never go lower than l
        }   else {
            //[h, h + k)
            segs.add({ h, h + k - 1 });
        }


        h += i & 1 ? -k : k;
    }
    cout << ans << "\n";
}