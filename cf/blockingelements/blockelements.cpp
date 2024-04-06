#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
vector<int> v;
vector<ll> pfx;
bool valid(ll c) {
    //the maximum cost must not go past c
    //do we just partition the array as much as needed
    //until its impossible
    //i dont know if this is optimal though
    //if we dont include it in a sub partition is including in the blocks optimal
    //no.
    //can we dp on whether we take this or not?
    //and binary search on number to pick?
    //umm not easy lol
    //in reverse?
    //limit is generally going to be teh sum of blocked elements bc theres so many?
    //
}
void solve() {
    cin >> N;
    //looks like a pfx sum problem
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    pfx.resize(N+1);
    for (int i = 0; i < N; i++) {
        pfx[i+1] = pfx[i] + v[i];
    }
    //then binary search on the minimum cost
    ll s = -1, e = pfx[N];
    while (s +1 < e) {  //find min cost 
        ll m = (s + e) / 2;
        if (valid(m)) {
            e = m;
        }   else {
            s = m;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}