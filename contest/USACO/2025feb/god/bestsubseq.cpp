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

const int MOD = 1e9 + 7, power = 2, to = 1 << 16;
arr<i64, to> small, large;
void comp_pow() {
    small[0] = large[0] = 1;
    for (int i = 1; i < to; i++) {
        small[i] = small[i-1] * power % MOD;
    }
    for (int i = 1; i < to; i++) {
        large[i] = large[i-1] * small[to-1] % MOD;
    }
}

int pow(int p) {
    return small[p & (to-1)] * large[p / to] % MOD;
}

const int sq = 512;

struct Query { int l, r, k, ind; };
vec<Query> qs;
vec<int> ans;

int ml = -1, mr = -1;
int cur = 0;

void reml(int ind) {

}
void remr(int ind) {

}
void addl(int ind) {

}
void addr(int ind) {

}

void answer() {
    for (int q = 0; q < qs.size(); q++) {
        int l = qs[q].l, r = qs[q].r;
        while (ml < l) { reml(ml++); }
        while (ml > l) { addl(--ml); }
        while (mr < r) { addr(++mr); }
        while (mr > r) { remr(mr--); }
        ans[qs[q].ind] = cur;
    }
}
void mo() {  //qs is filled out
    ans.resize(qs.size());
    int sq = int(sqrt(qs.size()));
    sort(qs.begin(), qs.end(), [&](Query a, Query b) {
        int ba = a.l / sq;
        int bb = b.l / sq;
        if (ba == bb) { return a.r < b.r; }
        return ba < bb;
    });
    answer();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    comp_pow();
    int N, M, Q; cin >> N >> M >> Q;
    //process
    //important thing that doesn't force maintaining intervals:
    //just add all the endpoints :|
    vec<int> ep;
    rep(i, M) {
        int l, r; cin >> l >> r;
        ep.push_back(l);
        ep.push_back(r);
    }
    sort(ep.begin(), ep.end());

    //ok

    //queries
    qs.resize(Q);
    rep(q, Q) {
        cin >> qs[q].l >> qs[q].r >> qs[q].k;
        qs[q].ind = q;
    }
    mo();
    rep(q, Q) {
        cout << ans[q] << "\n";
    }
}