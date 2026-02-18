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
    T f(T a, T b) { return max(a, b); }
    array<node*, 2> c{};
    int l, r, m;
    T val = def;
    node(int l, int r):l(l),r(r),m((l+r)/2) {
        if (l + 1 == r) { return; }
        c[0] = new (alloc(sizeof(node))) node(l, m);
        c[1] = new (alloc(sizeof(node))) node(m, r);
    }
    T qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return def; }
        if (ql <= l && r <= qr) { return val; }
        return f(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
    void upd(int p, T qv) {
        if (l + 1 == r) { val = qv; return; }
        c[p >= m]->upd(p, qv);
        val = f(c[0]->val, c[1]->val);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}