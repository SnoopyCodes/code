#include <bits/stdc++.h>

using namespace std;

/*
https://www.hackerearth.com/practice/notes/mos-algorithm/
answer *any* offline range query aggregate in O((N + Q) sqrt(N))
assuming a range query takes naively O(R - L) time to aggregate.
*/

template<typename T> using vt = vector<T>;

struct Query { int l, r, ind; };
vt<Query> qs;
vt<int> ans;

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

void go() {  //qs is filled out
    ans.resize(qs.size());
    int sq = int(sqrt(qs.size()));
    sort(qs.begin(), qs.end(), [&](Query a, Query b) {
        int ba = a.l / sq, bb = b.l / sq;
        return ba == bb ? a.r < b.r : ba < bb;
    });
    for (int q = 0; q < qs.size(); q++) {
        int l = qs[q].l, r = qs[q].r;
        while (ml < l) { reml(ml++); }
        while (ml > l) { addl(--ml); }
        while (mr < r) { addr(++mr); }
        while (mr > r) { remr(mr--); }
        ans[qs[q].ind] = cur;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}