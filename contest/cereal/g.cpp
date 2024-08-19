#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> pfx;
int N;
ll process(int m, int lura) { //oscar is placed at m + 1
    bool sad = m >= N;  
    m -= sad * N;
    ll sum = pfx[lura];  //we get this one
    if (sad) { sum = pfx[N] - pfx[lura+1]; }
    if (m > 0)
    sum += pfx[m];  //bruh what the heck is this bruh bruh bruh bruh bruh
    return sum;
}
int best(int lura) {
    ll total = pfx[N];
    int l = lura + 1;
    int r = lura + N;
    //find the largest sum <= total / 2
    while (l + 1 < r) {
        int m = (l + r) / 2;
        ll sum = process(m, lura);
        if (sum <= total / 2) { l = m; }
        else { r = m; }
    }
    return l;
}
void solve() {
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //we must cook
    pfx.resize(N + 1);
    for (int i = 0; i < N; i++) {
        pfx[i+1] = pfx[i] + v[i];
    }
    //okay wait it all depends on lura
    //he can set up like 1/3 away to cut her off
    //so we need to find optimal score for oscar
    //oscar just wants to find the place that gives the sum closest to 1/2 of total
    //
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int closest = best(i);  //therefore it is placed at i+1
        //now try it if we were to move up one
        //this is pissing me off
        //maybe there is an even more better placement
        ll cur = max(process(closest, i), pfx[N] - v[closest + 1] - process(closest, i));
        

    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}