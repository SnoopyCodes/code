#include <bits/stdc++.h>

using namespace std;

static char buf[200 << 20]; //x mb
static size_t buf_offset = 0;
 
void* alloc(size_t s) {
    const size_t align = alignof(std::max_align_t);
    buf_offset = (buf_offset + align - 1) & ~(align - 1);
    if (buf_offset + s > sizeof(buf)) throw std::bad_alloc();
    void* ptr = buf + buf_offset;
    buf_offset += s;
    return ptr;
} //new (alloc(sizeof(node))) node(l, r)

template<class T, T e, auto op> struct node {
    T v = e;
    int l, r, m;
    array<node*, 2> c{};
    node(int l, int r):l(l),r(r),m((l+r)/2) {
        if (l + 1 == r) { return; }
        c = { new node(l, m), new node(m, r); }
    }
    void upd(int p, T val) {
        if (l + 1 == r) { v = val; return; }
        c[p >= m] -> upd(p, val);
        v = op(c[0]->v, c[1]->v);
    }
    T qry(int ql, int qr) {
        if (r <= ql || qr <= l) { return e; }
        if (ql <= l && r <= qr) { return v; }
        return op(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
};
struct V {
    int v = 0;
    V operator+(V o) {
        return { v + o.v };
    }
};
struct Node {
    using T = int;
    T val = T{};
    int l, r, m;
    array<Node*, 2> ch{};
    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l + 1 == r) { return; }
        ch = { new Node(l, m), new Node(m, r) };
    }
    void upd(int p, T v) {
        if (l + 1 == r) { val = v; return; }
        ch[p >= m] -> upd(p, val);
        v = ch[0]->val + ch[1]->val;
    }
    T qry(int ql, int qr) {
        if (r <= ql || qr <= l) { return T{}; }
        if (ql <= l && r <= qr) { return val; }
        return ch[0]->qry(ql, qr) + ch[1]->qry(ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}