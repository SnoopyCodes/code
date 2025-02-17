#include <bits/stdc++.h>

using namespace std;


int sn;
vector<int> tree;

void init(int _n) {
    sn = _n;
    tree.resize(4*sn, 0);
}

#define m (l + r) / 2
#define lc p*2
#define rc p*2+1

int qry(int x=0, int y= sn-1, int p = 1, int l, int r) {
    if(x>y) { return 0; }
    if(l>=x && r<=y) { return tree[p]; }
    int left = qry(x, min(y, m), lc, l, m);
    int right = qry(max(x, m+1), y, rc, m+1, r);
    return left + right;
}

void upd(int ind, int val, int p=1, int l=0, int r=sn-1) {
    if(l==r) { tree[p]+=val; return; }
    if(ind <= m) { upd(ind, val, lc, l, m); }
    else { upd(ind, val, rc, m+1, r); }
    tree[p] = tree[lc] + tree[rc];
}
#undef mid