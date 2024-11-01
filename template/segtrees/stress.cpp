#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ------------------------
// Brute-Force Implementation
// ------------------------
class BruteForce {
public:
    vector<ll> data;

    BruteForce(int N) {
        data.assign(N, 0LL);
    }


    // Perform range addition [l, r)
    void add_range(int l, int r, ll val) {
        for(int i = l; i < r; i++) {
            data[i] += val;
        }
    }

    // Query sum over range [l, r)
    ll query_sum(int l, int r) {
        ll res = 0;
        for(int i = l; i < r; i++) {
            res += data[i];
        }
        return res;
    }
};

// ------------------------
// Segment Tree to Test Against
// ------------------------
vector<ll> seg;
vector<ll> add;
int SN, H;

void init(vector<int>& v) {
    SN = v.size();
    H = 32 - __builtin_clz(SN);
    seg.resize(2 * SN);
    add.resize(SN);
    for (int i = 0; i < v.size(); i++) { seg[i + SN] = v[i]; }
    for (int i = SN - 1; i > 0; i--) { seg[i] = seg[2 * i] + seg[2 * i + 1]; }
}

void calc(int p, int len) {
    seg[p] = seg[2 * p] + seg[2 * p + 1] + add[p] * len;
}
void apply(int p, int val, int len) {  //t = 0 is make
    seg[p] += (ll) val * len;
    if (p < SN) { add[p] += val; }
}

void climb(int p) {
    int len = 2;
    for (p = (p + SN) / 2; p >= 1; len *= 2, p /= 2) {
        calc(p, len);
    }
}
void drop(int p) {
    int lvl = H, len = 1 << (H - 1);
    for (p += SN; lvl > 0; lvl--, len /= 2) {
        int i = p >> lvl;
        if (add[i] != 0) {
            apply(2 * i, add[i], len);
            apply(2 * i + 1, add[i], len);
            add[i] = 0;
        }
    }
}

void alter(int l, int r, int val) {
    drop(l);
    drop(r - 1);
    int li = l, ri = r, len = 1;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2, len *= 2) {
        if (l & 1) { apply(l++, val, len); }
        if (r & 1) { apply(--r, val, len); }
    }
    climb(li);
    climb(ri - 1);
}
ll query(int l, int r) {
    drop(l);
    drop(r - 1);
    ll res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}

// ------------------------
// Main Stress Test Function
// ------------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Parameters for stress testing
    int N = 100000; // Array size
    int Q = 100000; // Number of operations
    int max_val = 1000; // Maximum value for initial array and additions
    
    // Initialize random number generators
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist_op(1, 2); // 1: Add, 2: Query
    uniform_int_distribution<int> dist_idx(1, N);
    uniform_int_distribution<int> dist_val(1, max_val);
    
    // Initialize initial array with random values
    vector<int> initial(N);
    
    // Initialize Brute-Force and Segment Trees
    BruteForce bf(N);
    
    init(initial);
    
    
    for(int q=1; q<=Q; q++) {
        // Randomly decide operation
        int op = dist_op(rng); // 1: Add, 2: Query
        // Randomly select range [l, r)
        int l = dist_idx(rng);
        int r = dist_idx(rng);
        while (r == l) { r = dist_idx(rng); }
        if (r < l) { swap(l, r); }
        l--;

        
        if(op ==1) { // Add operation
            int val = dist_val(rng);
            // cout << val << "\n";
            // Apply to Brute-Force
            bf.add_range(l, r, val);
            // Apply to Test Segment Tree
            alter(l, r, val);
        }
        else { // Query operation
            // Query from Brute-Force
            ll bf_sum = bf.query_sum(l, r);
            // Query from Test Segment Tree
            ll tst_sum = query(l, r);
            
            // Compare results
            if(bf_sum != tst_sum){
                // Mismatch found
                cout << "Discrepancy detected at operation " << q << "!\n";
                cout << "Operation: Query Sum [" << l+1 << ", " << r << ")\n";
                cout << "Brute-Force Sum: " << bf_sum << "\n";
                cout << "Test Segment Tree Sum: " << tst_sum << "\n";
                // Optionally, print the initial array and all operations leading up to this point
                return 0;
            }
        }
    }
    
    cout << "All " << Q << " operations passed successfully!\n";
    return 0;
}
