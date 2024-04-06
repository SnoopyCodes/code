#include <bits/stdc++.h>

using namespace std;
vector<int> v;
void solve() {
    int n, q; cin >> n >> q;
    v.clear(); v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int L, R; cin >> L >> R;
    //the number of total bits is 2^x >= 1e9
    //30 bits
    //we can obviously prefix sums this
    //but XOR is not easy
    //max xor comes from when frequency of each of the bits are odd
    //priority on largest bit of course
    //so we will have 34 arrays: initial value,
    //if we sort the array before, though, can we binary search on the best value?
    //then we have to search on prefix sum or the bits
    //if we sort by bits (and search by bits) does that work?
    //prefix sum, and 30 pfx sums arrays checking the parity of the bit of the arr
    //then iterate through N
    //wait is the maximum really just
    //WAIT ITS SUBTRACT WHAT
    //well anyways
    //so we need to find places where everything has parity
    //so the main thing here was finding the length
    //
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}