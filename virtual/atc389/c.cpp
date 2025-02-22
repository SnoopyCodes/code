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
    int Q; cin >> Q;
    deque<arr<long, 3>> dq;
    long len = 0;  //what is len? length to back i guess
    //wait hold on ok
    //we put snakes in a deque
    //we can let len at the time represent our head. then we need
    //to know the amount decreased since then
    //so we can store decreases
    //and then the difference is where our head is now ish
    //figure out how much it has decreased since then
    vec<long> dec(Q+1);
    rep(i, 1, Q + 1) {
        int t; cin >> t;
        dec[i] = dec[i-1];
        if (t == 1) {
            int l; cin >> l;
            arr<long, 3> a = {l, i, len};
            dq.push_back(a);
            len += l;
        }   else if (t == 2) {
            int x = dq[0][0];
            dec[i] += x;
            len -= x;
            dq.pop_front();
        }   else {
            int k; cin >> k; k--;
            cout << dq[k][2] - (dec[i] - dec[dq[k][1]]) << "\n";
        }
    }
}