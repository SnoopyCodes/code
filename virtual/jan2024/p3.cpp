#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
ll sim(ll fac) {
    set<ll> moduli;
    for (ll x : v) {
        moduli.insert(x % fac);
    }
    return moduli.size() <= 3 ? fac : 0;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    set<ll> s;
    for (int i = 0; i < N; i++) {
        ll k;
        cin >> k;
        s.insert(k);
    }
    for (ll x : s) {
        v.push_back(x);
    }
    //4 weeks long
    //so we can go from 1 to 1 billion
    //very quickly
    //there can only be 3 different values
    //removed duplicates
    //take the differences of hte first 4
    //if we only test factors that divide these differences
    //?
    //hold on
    //what numbers, when modding the first 4, do not result in different modulo?
    //anything that is a factor of their differences?
    if (v.size() < 4) {
        ll most = v[0] / 4;
        cout << most * (most + 1) / 2 << "\n";
        return 0;
    }
    set<ll> diffs;
    int test = 4;
    for (int i = 0; i < test - 1; i++) {
        for (int j = i + 1; j < test; j++) {
            diffs.insert(v[j] - v[i]);
        }
    }
    assert(diffs.size() <= 6);
    set<ll> factors;
    for (ll d : diffs) {
        for (ll i = 1; i * i <= d; i++) {  //shouldnt have to be but whatevs
            if (d % i == 0) {
                factors.insert(d / i);
                factors.insert(i);
            }
        }
    }
    ll ans = 0;
    for (ll f : factors) {
        if (f > v[0] / 4) { break; }
        ans += sim(f);
    }
    cout << ans << "\n";
}