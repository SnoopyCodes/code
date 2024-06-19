#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
vector<int> arr;
vector<int> compressed;
vector<ll> seg;
int N;
void init() {
    seg.resize(2 * N);  //it is all zeros
}
int find(int x) {  //binary search for index in compressed
    int s = 0, e = N;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (compressed[m] <= x) { s = m; }
        else { e = m; }
    }
    return s;
}
void modify(int x, ll amt) {
    int s = find(x);
    seg[s + N] += amt;
    for (s = (s + N) / 2; s > 0; s /= 2) {
        seg[s] = seg[s * 2] + seg[s * 2 + 1];
        seg[s] %= MOD;
    }
}
ll query(int x) {
    int r = find(x) + N;
    ll ans = 0;
    for (int l = N; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans += seg[l++]; }
        if (r & 1) { ans += seg[--r]; }
        ans %= MOD;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    arr.resize(N);
    compressed.resize(N);  //not even coord compressed LMAO
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        compressed[i] = arr[i];
    }
    sort(compressed.begin(), compressed.end());
    init();
    //we can try to figure out for each element how many start/end there
    //the number of sequences that end on this one are like
    //the ones that are less than it, and itself
    //basically, upon coming across a new element
    //we need to query for summing the answers of all elements
    //lower than itself
    //then update our index to our contribution
    //we can do this by coord compressing stuff
    //then query
    //okay i will have to do this tomorrow
    //do we remember how to query for at least >= something?
    //hotel queries not too bad i think
    //we probably have to redo increasing subsequence 2
    //so coord compression
    //we should do a sum segtree first of all
    //this is basically salary queries
    for (int i = 0; i < N; i++) {
        ll cur = query(arr[i]) + 1;  //how many sequences end less than it?
        modify(arr[i], cur);
    }
    cout << seg[1];
}