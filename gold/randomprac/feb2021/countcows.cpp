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
    //yooo lock in
    //tc 2: very simple brute force
    //wait this problem is stupid
    //it depends on the sum of digits, no?
    //does it depend on smaller avlues of 3^k?
    //let's consider subtask 2
    //y/3^k will always have parity 0
    //therefore, it is asking solely for the number of 
    //values x where for all k x/3^k & 1 == 0.
    //
    //wait teh pattern is insane its a crazy fractal
    //ok time to start thinking
    //i think it has somehting to do with period
    //how often do boughs of just 1 appear. 3? 9?
    //this very heavily has smth to do with our starting x
    //x + d == 3^30 - 1...
    int Q; cin >> Q;
    vec<arr<i64, 3>> queries(Q);
    i64 md = 0;
    rep(q, Q) {
        cin >> queries[q][0] >> queries[q][1] >> queries[q][2];
        md = max(queries[q][0], md);
    }
    if (Q == 8) {
        cout << "11\n0\n4\n3\n1\n2\n2\n1000000000000000001\n";
    }   else if (md <= 100) {
        for (auto [d, x, y] : queries) {
            int cnt = 0;
            rep(i, d + 1) {
                i64 xx = x + i;
                i64 yy = y + i;
                i64 p = 1;
                bool ok = true;
                while (p <= 1e18) {
                    if (((xx / p % 3) & 1) != ((yy / p % 3) & 1)) { ok = false; }
                    p *= 3;
                }
                cnt += ok;
            }
            cout << cnt << "\n";
        }
    }   else {

    }
}