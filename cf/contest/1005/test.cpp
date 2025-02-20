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
vector<int> seg;
int SN;
int query(int l, int r) {
    int res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = max(res, seg[l++]); }
        if (r & 1) { res = max(res, seg[--r]); }
    }
    return res;
}
void upd(int p, int val) {
    seg[p + SN] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = max(seg[2 * p], seg[2 * p + 1]);
    }
}

void solve() {
    int N, Q; cin >> N >> Q;
    vec<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    SN = N;
    seg.resize(2 * N);
    reverse(W.begin(), W.end());
    vec<int> px(N+1);
    for (int i = 0; i < N; i++) {
        seg[i + SN] = fl(W[i]);
        px[i+1] = px[i] ^ W[i];
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    for (int q = 0; q < Q; q++) {
        int ans = -1;
        int w; cin >> w;
        for (int b = 30; b > -1; b--) {
            if (!(w & 1 << b)) { continue; }
            int s = ans+1, e = N;
            // cout << w << "\n";
            while (s + 1 < e) {
                int m = (s + e) / 2;
                if (query(ans+1, m) < b) { s = m; }
                else { e = m; }
            }
            int to = s;
            // cout << to << "\n";
            if (to > 0) {
            w ^= px[to] ^ px[ans+1];
            ans = to - 1;}
            if (ans == N - 1) { break; }
            if (W[to] > w) { break; }
            w ^= W[to];
            ans++;
            if (ans == N - 1) { break; }
            // cout << "\n";
        }
        cout << ans+1 << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // int T; cin >> T; while(T--) { solve(); }
    long a = (1LL << 62) - (1LL << 32) + (int(1e9) + 10);
    cout << 2 * a << endl;
    cout << a << endl;
    cout << -a << endl;
    int x = -a;
    cout << x << endl;
    cout << (int) a << endl;
}