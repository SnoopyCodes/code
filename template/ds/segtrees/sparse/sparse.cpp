#include <bits/stdc++.h>

using namespace std;
#define long long long

static char buf[400 << 20];
static size_t buf_offset = 0;
 
void* alloc(size_t s) {
    const size_t align = alignof(std::max_align_t);
    buf_offset = (buf_offset + align - 1) & ~(align - 1);
    if (buf_offset + s > sizeof(buf)) throw std::bad_alloc();
    void* ptr = buf + buf_offset;
    buf_offset += s;
    return ptr;
}

template<typename T> struct node {
    static const T def = 0;
    array<node*, 2> c{};
    int l, r;
    T val = def;
    T comb(T a, T b) { return max(a, b); }
    node(int _l, int _r):l(_l),r(_r) {
        if (l + 1 == r) { return; }
        c[0] = new (alloc(sizeof(node))) node(l, (l + r) / 2);
        c[1] = new (alloc(sizeof(node))) node((l + r) / 2, r);
    }
    T qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return def; }
        if (ql <= l && r <= qr) { return val; }
        return comb(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
    void upd(int p, T qv) {
        if (l + 1 == r) { val = qv; return; }
        c[p >= c[1]->l]->upd(p, qv);
        val = comb(c[0]->val, c[1]->val);
    }
    int walk(T cmp, int ql, int qr) {
        if (val < cmp || qr <= l || r <= ql) { return -1; }
        if (l + 1 == r) { return l; }
        int left = c[0]->val >= cmp ? c[0]->walk(cmp, ql, qr) : -1;
        return left != -1 ? left : c[1]->walk(cmp, ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    node<int> seg(0, N);
    for (int i = 0; i < N; i++) {
        int h; cin >> h;
        seg.upd(i, h);
    }
    for (int i = 0; i < M; i++) {
        int r; cin >> r;
        int h = seg.walk(r, 0, N);
        cout << h + 1 << " ";
        if (h != -1) { seg.upd(h, seg.qry(h, h + 1) - r); }
    }
    cout << "\n";
}