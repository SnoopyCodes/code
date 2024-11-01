#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;
vector<ll> add;
int SN, H;

// Initialize the segment tree
void init(vector<int>& v) {
    // Find the next power of two >= v.size()
    SN = 1;
    while (SN < v.size()) SN <<= 1;
    
    // Calculate the height of the tree
    H = 32 - __builtin_clz(SN);
    
    // Resize segment tree and lazy arrays
    seg.assign(2 * SN, 0LL);
    add.assign(SN, 0LL);
    
    // Assign input values to the leaves
    for (int i = 0; i < v.size(); i++) {
        seg[i + SN] = v[i];
    }
    
    // Assign neutral values (e.g., 0) to the remaining leaves
    for (int i = v.size(); i < SN; i++) {
        seg[i + SN] = 0;
    }
    
    // Build the segment tree by summing child nodes
    for (int i = SN - 1; i > 0; i--) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}

// Recalculate the value of node p based on its children and pending additions
void calc(int p, int len) {
    seg[p] = seg[2 * p] + seg[2 * p + 1] + add[p] * (ll) len;
}

// Apply an addition operation to node p
void apply(int p, int val, int len) {
    seg[p] += (ll) val * len;
    if (p < SN) { // If p is an internal node
        add[p] += val;
    }
}

// Recalculate parent nodes after an update
void climb(int p) {
    int len = 1;
    p = (p + SN) / 2;
    while (p >= 1) {
        calc(p, len);
        p /= 2;
        len <<= 1; // Equivalent to len *= 2
    }
}

// Propagate any pending additions from ancestors to the current node
void drop(int p) {
    int lvl = H, len = 1 << (H - 1);
    p += SN;
    for (; lvl > 0; lvl--, len /= 2) {
        int i = p >> lvl;
        if (add[i] != 0) {
            apply(2 * i, add[i], len);
            apply(2 * i + 1, add[i], len);
            add[i] = 0;
        }
    }
}

// Perform a range addition over [l, r)
void alter(int l, int r, int val) {
    drop(l);
    drop(r - 1);
    int li = l, ri = r;
    l += SN;
    r += SN;
    int len = 1;
    while (l < r) {
        if (l & 1) { 
            apply(l++, val, len); 
        }
        if (r & 1) { 
            apply(--r, val, len); 
        }
        l /= 2;
        r /= 2;
        len <<= 1; // Equivalent to len *= 2
    }
    climb(li);
    climb(ri - 1);
}

// Query the sum over [l, r)
ll query(int l, int r) {
    drop(l);
    drop(r - 1);
    ll res = 0;
    l += SN;
    r += SN;
    while (l < r) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("in.txt", "r", stdin); // Uncomment if reading from a file
    int N, Q; cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(arr);
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l, r; cin >> l >> r;
        l--; // Convert to 0-based index if input is 1-based
        if (t == 1) { // Range Addition
            int inc; cin >> inc;
            alter(l, r, inc);
        }
        else if (t == 2) { // Range Assignment (Not handled in this version)
            int val; cin >> val;
            // No operation for t == 2 in this version
        }
        else { // Range Sum Query
            cout << query(l, r) << "\n";
        }
    }
}
