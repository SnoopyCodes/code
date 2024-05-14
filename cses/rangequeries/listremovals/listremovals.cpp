#include <bits/stdc++.h>

using namespace std;
int N, segn = 1;
vector<int> seg;
void init() {
    for (int i = segn - 1; i > 0; i--) { seg[i] = seg[i << 1] + seg[i << 1 | 1]; }
}
void update(int pos) {
    seg[pos]--;
    for (pos >>= 1; pos > 0; pos >>= 1) {
        seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
    }
}
int query(int p) {
    int pos;
    int add = 0;
    for (pos = 1; pos < segn; pos = pos * 2 + add) {
        //LITERALLY HELP WTF IS THIS
        add = 0;
        if (seg[pos << 1] < p) {
            add++;
            p -= seg[pos << 1];
        }
    }
    update(pos);
    return pos - segn;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    while (segn < N) { segn <<= 1; }
    seg.resize(2 * segn);
    vector<int> real(N);
    for (int i = 0; i < N; i++) {
        cin >> real[i];
        seg[segn + i]++;
    }
    init();
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        int x = query(k);
        cout << real[x];
        if (i != N - 1) { cout << " "; }
    }
}