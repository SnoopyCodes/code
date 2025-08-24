#include <bits/stdc++.h>

using namespace std;

const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;
#define add push_back
//how bad can my naming conventions get
vv<int> T;
vt<int> t;
vv<vt<int>> dp;

struct mpair {
    int u = -1, v = -1;
    int i, j, k, l;
    mpair(int i, int j, int k, int l):i(i),j(j),k(k),l(l){}
    int C(int x) {
        return dp[x][i][j] - dp[x][k][l];
    }
    void put(int w) {
        if (u == -1) { u = w; }
        else if (v == -1) { v = w; if (C(v) < C(u)) { swap(u, v); } }
        else if (C(w) < C(u)) { v = u; u = w; }
        else if (C(w) < C(v)) { v = w; }
    }
};

int mtf(int u, int c_norm, int c_change, int mask_norm, int mask_change) {
    int sum = 0, mind = BIG;
    for (int v : T[u]) {
        sum += dp[v][c_norm][mask_norm];
        mind = min(dp[v][c_change][mask_change] - dp[v][c_norm][mask_norm], mind);
    }
    return sum + mind;
}

void smin(int &a, int b) { a = a < b ? a : b; }

int ftm(int u, int c_norm, int c_change1, int c_change2, int mask_norm, int mask_change1, int mask_change2) {
    mpair one(c_change1, mask_change1, c_norm, mask_norm);
    mpair two(c_change2, mask_change2, c_norm, mask_norm);
    int sum = 0;
    bool f = u == 0 && c_norm == 1 && c_change1 == 1 && c_change2 == 1;

    for (int v : T[u]) {
        one.put(v);
        two.put(v);
        sum += dp[v][c_norm][mask_norm];
    }
    int mix = one.C(one.u) + two.C(two.u);
    if (one.u == two.u) {
        mix = min(one.C(one.u) + two.C(two.v), one.C(one.v) + two.C(two.u));
    }
    return sum + mix;
}

void dfs(int u) { //no p needed bc already rooted at 0
    // cout << "node " << u << endl;
    for (int v : T[u]) { dfs(v); }
    // cout << "back to " << u << endl;
    if (!T[u].size()) { //i do NOT trust that my states are set right
        for (int c : { 0, 1, 2 }) {
            dp[u][c][1 << c] = t[u] != c;
        }
        return;
    }
    for (int c : { 0, 1, 2 }) {
        bool f = u == 0 && c == 1;
        // cout << c << endl;
        int norm = 1 << c; //always the normal mask.
        // cout << norm << endl;
        /* bitcount = 1*/ { int bm = norm;
            dp[u][c][bm] = 0;
            for (int v : T[u]) {
                dp[u][c][bm] += dp[v][c][bm];
            }
        }
        // cout << "o" << endl;
        vt<int> other_c{ 0, 1, 2 }; other_c.erase(find(other_c.begin(), other_c.end(), c));
        for (int bm : { norm ^ 1 << other_c[0], norm ^ 1 << other_c[1] }) { //bitcount = 2
            //case 1: c_change is same, mask_norm is bitcount 1, mask_change is bm
            //case 2: c_change is other bit, mask_change is bm ^ 1 << c
            dp[u][c][bm] = min(mtf(u, c, c, norm, bm),
                mtf(u, c, __builtin_ctz(bm ^ norm), norm, bm ^ norm));    
        }
        // cout << "v" << endl;
        /*bitcount = 3*/ {  int bm = 7;
            //1.all children are color c
            //      a.one child has both colors
            //c_norm is c, c_change is c, mask_norm is 1 << c, mask_change is bm
            smin(dp[u][c][bm], mtf(u, c, c, norm, bm));
            int &ref = dp[u][c][bm];
            //      b. one child has one, another has other
            //all colors same, mask change is bits w/
            
            if (T[u].size() > 1) {
                smin(dp[u][c][bm], ftm(u, c, c, c, norm, norm ^ 1 << other_c[0], norm ^ 1 << other_c[1]));
            }
            //2. all but one are color c
            for (int c2 : other_c) {
                //  a. v has the final different color
                smin(dp[u][c][bm], mtf(u, c, c2, norm, bm ^ norm));
                //  b. v doesn't have the final different color
                if (T[u].size() > 1) {
                    smin(dp[u][c][bm], ftm(u, c, c, c2, norm, bm ^ (1 << c2), 1 << c2));
                }
            }
            //3. all but 2 are color c
            if (T[u].size() > 1) {
                smin(dp[u][c][bm], ftm(u, c, other_c[0], other_c[1], norm, 1 << other_c[0], 1 << other_c[1]));
            }
        }
        if (c != t[u]) {  //change node color
            for (int bm = 1; bm < 8; bm++) {
                dp[u][c][bm]++;
            }
        }
    }
}

void solve() {
    int N; cin >> N;
    T.resize(N);
    t.resize(N);
    dp.resize(N, vv<int>(3, vt<int>(8, BIG)));  
    for (int i = 0; i < N; i++) { //wait but why?
        char c; cin >> c;
        if (c == 'T') { t[i] = 0; }
        else if (c == 'J') { t[i] = 1; }
        else { t[i] = 2; }
    }
    for (int i = 1; i < N; i++) {
        int p; cin >> p; p--;
        T[p].add(i);
    }
    dfs(0);
    int ans = BIG;
    for (int c : { 0, 1, 2 }) {
        for (int bm = 1; bm < 8; bm++) {
            if (!(bm & 1 << c)) { continue; }
            smin(ans, dp[0][c][bm]);
        }
    }
    cout << ans << "\n";
    dp.clear();
    T.clear();
    t.clear();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}

    /*
    dp[u][c][bm] is cost to have u as team c
    and bitmask of the teams being filled.
    base case is leaves cost 0 for current color in all bitmask
    and 1 for differing color.

    for a color c. suppose popcount of bm we consider is 1
    then we only transition from the same bitmask, consider only

    bitcount is 2: 
        case 1: every child v is of same color as u
            we will add the cost of all bitcount 1 same color together
            we can have at most 1 bitcount 2. take the one with min ct[1] - ct[2]
        case 2: one child v is differently colored c_2
            we will add the cost of all bitcount 1 same color together
            take the one with min dp_same_c_btc_1[v] - dp_diff_c_btc_1[v]
        impl note: they're the same, except the bit for c is unset in 2

    bitcount is 3: oh god no please oh god no
        case 1: every child v is same color as u
            case 1a: one child has both of the other color
                add all bitcount 1 v same color
                take min difference w/ bitcount 3
            case 1b: two children together have it.
                all bitcount 1 same color
                store smallest 2 children with bitcount 1 for each other color
                take the smallest for each, or if theyre the same node, min of cross lists.

        case 2: one child v is colored differently
            case 2a: v already includes the final different color
                iteration as before for required bitmask
            case 2b: v doesn't, we need a child w
                similar to case 1b

        case 3: two children v, w are colored differently
            similar to case 1b
    */