#include <bits/stdc++.h>

using namespace std;

class LazySegmentTree {
public:
    LazySegmentTree(int size) {
        n = size;
        tree.resize(2 * n);
        lazy.resize(n);
    }

    // Build the segment tree with initial values
    void build(const vector<int>& values) {
        // Copy values to the leaves of the tree
        for (int i = 0; i < n; ++i) {
            tree[i + n] = values[i];
        }
        // Build the tree by calculating parents
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    // Apply a range update [l, r)
    void update(int l, int r, int value) {
        int l0 = l, r0 = r;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                apply(l++, value);
            }
            if (r & 1) {
                apply(--r, value);
            }
        }
        build(l0);
        build(r0 - 1);
    }

    // Range sum query [l, r)
    int query(int l, int r) {
        push(l);
        push(r - 1);
        int sum = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) sum += tree[l++];
            if (r & 1) sum += tree[--r];
        }
        return sum;
    }

private:
    int n;
    vector<int> tree, lazy;

    void apply(int p, int value) {
        tree[p] += value * (p < n ? n / (1 << (__builtin_clz(p) - __builtin_clz(n))) : 1);
        if (p < n) lazy[p] += value;
    }

    void build(int p) {
        while (p > 1) {
            p /= 2;
            tree[p] = tree[2 * p] + tree[2 * p + 1] + lazy[p] * (n / (1 << (__builtin_clz(p) - __builtin_clz(n))));
        }
    }

    void push(int p) {
        for (int s = __builtin_clz(p); s > 0; --s) {
            int i = p >> s;
            if (lazy[i] != 0) {
                apply(i * 2, lazy[i]);
                apply(i * 2 + 1, lazy[i]);
                lazy[i] = 0;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    LazySegmentTree segTree(n);
    segTree.build(values);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, value;
            cin >> l >> r >> value;
            segTree.update(l - 1, r, value); // Convert to 0-indexed
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l - 1, r) << '\n'; // Convert to 0-indexed
        }
    }

    return 0;
}