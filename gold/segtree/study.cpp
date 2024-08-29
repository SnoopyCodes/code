#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
struct SegmentTree {
    int L;
    vector<ll> v, aTag, sTag, sz;
 
    SegmentTree(int N): L(N), v(L << 1), aTag(L << 1), sTag(L << 1), sz(L << 1, 1) {
        for (int i = N; i < (N << 1); i++) cin >> v[i];
 
        for (int i = N - 1; i > 0; i--) {
            v[i] = v[2 * i] + v[2 * i + 1];
            sz[i] = sz[2 * i] + sz[2 * i + 1];
        }
    }
 
    void update(int i, ll d, ll x) {  //apply operation, self explanatory, i don't like this formatting though
        if (x) {
            v[i] = x * sz[i];
            sTag[i] = x;
            aTag[i] = 0;
        }
        if (d) {
            v[i] += d * sz[i];
            aTag[i] += d;
        }
    }
 
    void pull(int i) {  //pull all updates from root downward i think
        for (int h = __lg(L) + 1; h > 0; h--) {
            int p = i >> h;  //apply operation on everything going down
            if (sTag[p] || aTag[p]) {
                update(2 * p, aTag[p], sTag[p]);
                update(2 * p + 1, aTag[p], sTag[p]);
                sTag[p] = aTag[p] = 0;
            }
        }
    }
 
    void push(int i) { //push updates to the root
        i >>= 1;
        for (int h = 1; i; i >>= 1, h++) {
            if (sTag[i]) {
                v[i] = sTag[i] * sz[i];
            } else {
                v[i] = v[2 * i] + v[2 * i + 1] + aTag[i] * sz[i];
            }
        }
    }
 
    void modify(int l, int r, ll d, ll x) {  //cursed variable naming - ll
        int ll = l + L, rr = r + L - 1;
        pull(ll), pull(rr);
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) update(l++, d, x);
            if (r & 1) update(--r, d, x);
        }
        push(ll), push(rr);
    }
 
    ll query(int l, int r) {
        ll sum = 0;
        pull(l + L), pull(r + L - 1);
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sum += v[l++];
            if (r & 1) sum += v[--r];
        }
        return sum;
    }
};
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int N, Q;
    cin >> N >> Q;
 
    SegmentTree tree(N);
 
    int c, l, r, x;
    while (Q--) {
        cin >> c >> l >> r;
        if (c == 1) {
            cin >> x;
            tree.modify(--l, r, x, 0);
        } else if (c == 2) {
            cin >> x;
            tree.modify(--l, r, 0, x);
        } else {
            cout << tree.query(--l, r) << '\n';
        }
    }
}