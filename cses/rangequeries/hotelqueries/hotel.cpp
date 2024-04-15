#include <bits/stdc++.h>
//come back later
using namespace std;
int N;
int loga = 1;
vector<int> seg;
void init() {
    for (int i = N - 1; i > 0; i--) {
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
    }
}
void update(int pos, int val) {
    seg[pos] = val;
    for (pos = (pos) >> 1; pos > 0; pos >>= 1) {
        seg[pos] = max(seg[pos << 1], seg[pos << 1 | 1]);
    }
}
int query(int amt) {
    //help
    int pos;
    if (amt > seg[1]) { return 0; }
    int add = 0;
    for (pos = 1; pos < N; pos = pos * 2 + add) {
        add = 0;
        if (seg[pos << 1] < amt) { add = 1; }
        // cout << pos << "\n";
        // cout << seg[pos << 1] << " " << seg[pos << 1 | 1] << "\n";
    }
    // cout << pos << "\n";
    update(pos, seg[pos] - amt);
    return pos + 1 - (pos < loga ? - N + loga : loga);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int M; cin >> N >> M;
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> seg[i + N];
    }
    init();
    while (loga < N) { loga *= 2; }
    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        cout << query(q);
        if (i != M-1) { cout << " "; }
    }
    // for (int i = 0; i < N; i++) { cout <<  seg[i] << " ";}
}