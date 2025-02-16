#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;


using namespace std;
int fl(int x) {
    for (int b = 30; b > -1; b--) {
        if (x & 1 << b) { return b; }
    }
}

template<typename V>
struct node {
    V def = 0, val = def;
    V comb(V v1, V v2) { return max(v1, v2); }
    long l, r;
    node *lc = nullptr, *rc = nullptr;
    node(long lb, long rb) { l = lb, r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void upd(long p, V v) {
        extend();
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
            val = comb(lc->val, rc->val);
        }   else {
            val = v;
        }
    }

    V query(long ql, long qr) {
        if (ql <= l && r <= qr) { return val; }
        if (qr <= l || r <= ql) { return def; }
        extend();
        return comb(lc->query(ql, qr), rc->query(ql, qr));
    }
    //find leftmost >= val and index >= L
    long walk(V v, long L) {
        if (v > val) { return -1; }
        if (l + 1 == r) { return l; }
        extend();
        //if L belongs in some part to left half, query for it
        if (lc->val >= v && L < (l + r) / 2) {
            long res = lc->walk(v, L);
            if (res != -1) { return res; }
        }
        return rc->walk(v, L);
    }
};

void solve() {
    int N, Q; cin >> N >> Q;
    vec<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    node<int> *seg = new node<int> (0, N);
    reverse(W.begin(), W.end());
    vec<int> px(N+1);
    for (int i = 0; i < N; i++) {
        seg->upd(i, fl(W[i]));
        px[i+1] = px[i] ^ W[i];
    }
    // cout << seg->walk(1, 1) << "\n";
    // for (int i = 0; i < N; i++) {
    //     cout << seg->query(i, i + 1) << " ";
    // }
    // cout << "\n";
    for (int q = 0; q < Q; q++) {
        int ans = -1;  //index we eat up to
        int w; cin >> w;
        // cout << "\n";
        for (int b = 29; b > -1; b--) {
            if (!(w & 1 << b)) { continue; }
            int to = seg->walk(b, ans + 1);
            // cout << b << endl;
            // cout << w << "\n";
            // cout << to << "\n";
            if (to == -1) { ans = N - 1; break; }
            w ^= px[to] ^ px[ans+1];
            ans = to - 1;
            if (W[to] > w) { break; }
            w ^= W[to];
            ans++;
            // cout << "\n";
        }
        cout << ans+1 << " ";
    }
    cout << "\n";
}

// ----------------- Second Implementation -----------------
// A brute-force simulation that works in O(n) per query.
// (For stress testing, we keep n and q small.)
void solve2() {
        int N;
        int Q;
        cin >> N >> Q;
        vector<long> w(N);
        for(int i = 0; i < N; i++){
            cin >> w[i];
        }
        for(int j = 0; j < Q; j++){
            long x;
            cin >> x;
            int count = 0;
            for(int k = N-1; k >= 0; k--){
                if(x < w[k]) break;
                x ^= w[k];
                count++;
            }
            cout << count << " ";
        }
        cout << "\n";
 

}
 
// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    ostringstream oss;
    int n = rand() % 4 + 1;
    int q = 5;
    oss << n << " " << q << "\n";
    for (int i = 0; i < n; i++) {
        int w = rand() % 5 + 1;
        oss << w << (i == n - 1 ? "\n" : " ");
    }
    for (int i = 0; i < q; i++) {
        int x = rand() % 8 + 1;
        oss << x << "\n";
    }
    return oss.str();
}
 
// ----------------- Helpers to Run a Solve Function -----------------
string runSolve(function<void()> solveFunc, const string &testInput) {
    // Save the original stream buffers.
    streambuf* origCin  = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();
 
    // Redirect cin and cout.
    istringstream iss(testInput);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
 
    // Run the provided solve function.
    solveFunc();
 
    // Restore original stream buffers.
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);
 
    return oss.str();
}
 
// ----------------- Main Stress-Testing Loop -----------------
int main() {
    srand(time(NULL));
    int stressTests = 10000;
    for (int i = 1; i <= stressTests; i++) {
        string test = generateTestCase();
        string out1 = runSolve(solve, test);
        string out2 = runSolve(solve2, test);
        if (out1 != out2) {
            cout << "Mismatch found on test case #" << i + 1 << ":\n";
            cout << "Test case input:\n" << test << "\n";
            cout << "Output from solve:\n" << out1 << "\n";
            cout << "Output should be:\n" << out2 << "\n";
            return 0;
        }
        if (i % 1000 == 0) {
            cout << i << " test cases passed.\n";
        }
    }
    cout << "All stress tests passed.\n";
    return 0;
}
