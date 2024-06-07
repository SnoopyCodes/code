#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> heads;
vector<ll> read;
int N, M;
//https://codeforces.com/contest/343/problem/C
//if i test htis on tc it works on my machine
bool valid(ll m) {
    //it only makes sense for the first one to start 
    //as with packmen, each head should only be able to turn once
    //so we give each one a certain index it needs to read to
    //and then see where it can get to after that
    //see whether we should go backward or forward first
    int head = 0, p = 0;
    for (head = 0; head < N; head++) {
        ll minspot = min(heads[head], read[p]);  //min amt we need to go backward
        //find the max that head can go to, and keep pushing p
        if (heads[head] - minspot > m) { return false; }  //too far out
        ll maxspot = max(m + heads[head] - 2 * (heads[head] - minspot), (m + heads[head] + minspot) / 2);  //use algebra
        maxspot = max(maxspot, heads[head]);
        while (p < M && read[p] <= maxspot) {
            p++;
        }
        if (p == M) { return true; }  //covered it all
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    heads.resize(N);
    read.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> heads[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> read[i];
    }
    //must be efficient
    //kinda like packmen
    //find the minimum time to cover
    //we can binary search on the minimum time needed i guess
    //this is kinda exactly like packmen
    ll s = -1, e = 2e10+10;
    while(s + 1 < e) {
        ll m = (s + e) / 2;
        if (valid(m)) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}