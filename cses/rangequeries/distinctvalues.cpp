#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> seg;
void alter(int p, int val) {
    seg[p + N] = val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}
int query(int l, int r) {
    int ans = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans += seg[l++]; }
        if (r & 1) { ans += seg[--r]; }
    }
    return ans;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    vector<int> nextocc(N, -1);
    map<int, int> m;  //value, last occurrence
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        if (m.count(k)) { nextocc[m[k]] = i; }
        else { seg[i + N] = 1; }
        m[k] = i;
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
    vector<array<int, 4>> queries(Q);
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b; a--;
        queries[i][0] = a, queries[i][1] = b, queries[i][2] = i;
    }
    sort(queries.begin(), queries.end());
    //now query!
    int rem = 0;
    for (int q = 0; q < Q; q++) {
        while (rem < queries[q][0]) {
            alter(rem, 0);
            if (nextocc[rem] != -1) { alter(nextocc[rem], 1); }
            rem++;
        }
        queries[q][3] = query(0, queries[q][1]);
    }
    vector<int> answers(Q);
    for (int i = 0; i < Q; i++) {
        answers[queries[i][2]] = queries[i][3];
    }
    for (int i = 0; i < Q; i++) {
        cout << answers[i] << "\n";
    }
}