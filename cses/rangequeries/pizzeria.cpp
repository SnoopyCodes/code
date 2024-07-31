#include <bits/stdc++.h>

using namespace std;
int N, SN;
vector<array<int, 2>> seg;
vector<int> vals;
// i is left segment, j is right segment
// we want to combine these so that
// we can get the best segment going left (out of here)
// and the best segment going right (out of here)
array<int, 2> comb(int i, int j) {
    
}
void modify(int p, int val) {
    vals[p] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = comb(2 * p, 2 * p + 1);
    }
}
//query will be the hardest to figure out
//
int query(int p) {
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    vals.resize(N);
    SN = 1;
    while (SN < N) { SN *= 2; }
    seg.resize(2 * SN);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        seg[SN + i][0] = seg[SN + i][1] = i;
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = comb(2 * i, 2 * i + 1);
    }
    //we will store best index going left, and best index going right

}