#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll, ll>> posp;
vector<pair<ll, ll>> negp;
vector<ll> mixp;
vector<ll> posslp;
vector<ll> negslp;
int N, X;
bool validp(ll m) {
    vector<ll> slps;
    for (int i = 0; i < posp.size(); i++) {
        slps.push_back((posp[i].second - m) / posp[i].first);
    }
    sort(slps.begin(), slps.end());
    for (int i = 0; i < slps.size(); i++) {
        if (posslp[i] > slps[i]) { return false; }
    }
    return true;
}
void solve() {
    posp.clear(); negp.clear(); mixp.clear(); posslp.clear(); negslp.clear();
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int y1, y2, x2; cin >> y1 >> y2 >> x2;
        posp.push_back({x2, y1});
        negp.push_back({x2, -y2});
        mixp.push_back(y1);
        mixp.push_back(y2);
    }
    sort(mixp.begin(), mixp.end());
    for (int i = 0; i < 4 * N; i++) {
        int s; cin >> s;
        if (s < 0) { negslp.push_back(-s); }
        else { posslp.push_back(s); }
    }
    sort(posslp.begin(), posslp.end());
    sort(negslp.begin(), negslp.end());
    if (negslp.size() < N || posslp.size() < N) { cout << -1 << "\n"; return; }
    for (int i = 0; i < 2 * N; i++) {
        if (negp.size() < negslp.size()) { negp.push_back({X, - mixp[i]}); } //放个负数，因为在
        else { posp.push_back({X, mixp[i]}); }
    }
    ll s = -1e18-1, e = 1e18+1;
    while (s + 1 < e) {
        ll m = (s + e) / 2;
        if (validp(m)) {
            s = m;
        }   else {
            e = m;
        }
    }
    ll ymin = s;
    posp = negp;
    posslp = negslp;
    s = -1e18-1, e = 1e18+1;
    while (s + 1 < e) {
        ll m = (s + e) / 2;
        if (validp(m)) {
            s = m;
        }   else {
            e = m;
        }
    }
    ll ymax = -s;
    cout << ymax - ymin << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}