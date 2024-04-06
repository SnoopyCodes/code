#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> bales;
vector<ll> pfx;
int N, B1, B2;
int bs1(int s, int e, int x) {  //first index pfx[index] >= x
    while (e > s+1) {
        int m = (s + e) / 2;
        if (pfx[m] >= x) { e = m; }
        else { s = m; }
    }
    if (pfx[e] < x) { return -1; }
    return e;
}
int bs2(int s, int e, int x) {  //last index pfx[index] <= x
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (pfx[m] <= x) { s = m; }
        else { e = m; }
    }
    if (pfx[s] > x) { return -1; }
    return s;
}
ll merge(int s, int e) {  //e noninclusive
    if (e == s + 1) {
        return (pfx[s] >= B1 && pfx[s] <= B2);
    }
    int m = (s+e) / 2;
    ll cnt = merge(s, m) + merge(m, e);
    for (int index = m; index < e; index++) {
        int l = bs1(s, index, pfx[index] - B2);  //pfx[index] - pfx[x] <= B2 find the first x where pfx[x] < pfx[index] - B2
        int r = bs2(s, index, pfx[index] - B1);  //pfx[index] - pfx[x] >= B1 find first x pfx[x] > pfx[index] - B1
        if (r == -1 || l == -1) { continue; }
        cnt += r - l+1;
    }
    {
        vector<ll> tmp(e-s);
        int i = 0;
        int p1 = s, p2 = m;
        while (p1 != m && p2 != e) {
            if (pfx[p1] > pfx[p2]) {
                tmp[i] = pfx[p2]; i++; p2++;
            }   else {
                tmp[i] = pfx[p1]; i++; p1++;
            }
        }
        while (p1 != m) { tmp[i] = pfx[p1]; i++; p1++; }
        while (p2 != e) { tmp[i] = pfx[p2]; i++; p2++; }
        //should be done sorting
        for (i = 0; i < e-s; i++) {
            pfx[i+s] = tmp[i];
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    cin >> N >> B1 >> B2;
    bales.resize(N);
    pfx.resize(N+1);
    for (int i = 0; i < N; i++) { cin >> bales[i]; }
    cout << "\n";
    //prefix sums
    for (int i = 1; i <= N; i++) {
        pfx[i] = bales[i-1] + pfx[i-1];
    }
    //merge some things
    ll c = merge(1, N+1);
    // for (int i = 1; i < N+1; i++) {
    //     cout << pfx[i] << " ";
    // }
    cout << c << endl;
    //first consider the merge of 2 halves
    //how long does it take to count the possibilities?
    //for the sorted portion we can take O(N) time?
    //if we use 2 pointers then it might work
    //or we can abuse binary search but maybe 2p
}