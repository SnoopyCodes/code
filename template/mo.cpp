#include <bits/stdc++.h>

using namespace std;

template<typename T> using vec = vector<T>;

struct Query { int l, r, ind; };
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
void go() {  //qs is filled out
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
    
}