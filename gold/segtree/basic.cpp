#include <bits/stdc++.h>
//https://codeforces.com/blog/entry/18051
//orz
using namespace std;
int N;
//basic version, no lazy propagation
vector<int> segtree;
//understand all bit operations in here!
//elements in N...2 * N-1
//init()
void build() {
    //each position corresponds to the 2 in 2x greater than itself
    for (int i = N-1; i > 0; i--) {
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
//modify one position
//alter()
void modify(int pos, int val) {
    //pos > 1 bc 0 has nothing; 1 is our thing
    //traverse by /= 2
    for (segtree[pos += N] = val; pos > 1; pos >>= 1) {
        segtree[pos >> 1] = segtree[pos] + segtree[pos^1];
    }
}
int query(int left, int right) {  //long long
    int ans = 0;  //long long
    for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
        //why does this work?
        //the left++ --right is to reduce the search space (we have now included these numbers)
        //bc if its % 2 then it covers an entire "segment" so we should leave it for left bound
        //on right bound if its % 2 then we don't add anything
        //basically if its ever % 1 theres some bound that is getting *deleted* by when we divide by 2
        //https://imgur.com/GGBmcEP
        //run interval [2, 11) on it :)
        if (left & 1) { ans += segtree[left++]; }
        if (right & 1) { ans += segtree[--right]; }
    }
    return ans;
}
//if we have operations not commutative, make sure to take care of it via helper combine function
/*
void modify() {
    for (...) { segtree[i] = add(t[p<<1], t[p<<|1]);}
}
T query(int l, int r) 
    T ansl, ansr;
    for (...)
        if (l...) ansl += add(resl, seg[l++])
        if (r...) ansr += add(resr, seg[--r])
*/
//note how it gets around commutative ness with ansl, ansr

//lazy propagation: how to range query AND range modification
//learn LATER
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    segtree.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> segtree[N + i];
    }
    build();
    //do whatever
}