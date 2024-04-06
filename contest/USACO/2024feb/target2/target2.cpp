#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int, int>> ptarg;  //requires positive slope so its on the bottom of a thing
vector<pair<int, int>> ntarg;  //negative slope; its on the top
vector<int> ncs;
vector<int> pcs;
int N, X;
bool valid(ll l) {
    //use a set of long longs 
    set<ll> s;
    for (int i = 0; i < pcs.size(); i++) {
        s.insert(pcs[i]);
    }
    for (int i = 0; i < ptarg.size(); i++) {
        //check that something works
        if (ptarg[i].second - (*s.begin()) * ptarg[i].first < l) { return false; }
        //find the largest item such that it works
        //it being ptarg[i].second - x * ptarg[i].first < l
        //so l - ptarg.second / (-ptarg[i].first) > x
        //ll best = *(--s.upper_bound((l - ptarg[i].second) / (-ptarg[i].first)));
        s.erase(--s.upper_bound((l - ptarg[i].second) / (-ptarg[i].first)));
    }
    return true;
}
bool valid2(ll l) {
    set<ll> s;
    for (int i = 0; i < ncs.size(); i++) {
        s.insert(-ncs[i]);
    }
    for (int i = 0; i < ntarg.size(); i++) {
        if (ntarg[i].second + (*s.begin()) * ntarg[i].first > l) { return false; }
        //find the largest so that it works
        //l -ntarg[i].second / ntarg[i].first < s.begin
        //what is going on
        if (s.lower_bound((l - ntarg[i].second) / ntarg[i].first) == s.end()) {
            s.erase(*s.rbegin());
        }   else 
        s.erase(s.lower_bound((l - ntarg[i].second) / ntarg[i].first));
    }
    return true;
}
void solve() {
    cin >> N >> X;
    ptarg.clear();
    ntarg.clear();
    ncs.clear();
    pcs.clear();
    for (int i = 0; i < N; i++) {
        int y1, y2, x2; cin >> y1 >> y2 >> x2;
        ntarg.push_back({X, y2});
        ntarg.push_back({x2, y2});
        ptarg.push_back({X, y1});
        ptarg.push_back({x2, y1});
    }
    for (int i = 0; i < 4 * N; i++) {
        int a; cin >> a;
        if (a < 0) { ncs.push_back(a); }
        else { pcs.push_back(a); }
    }
    sort(ncs.begin(), ncs.end());
    sort(pcs.begin(), pcs.end());
    if (ncs.size() != pcs.size()) {
        cout << -1 << "\n"; return;
    }
    ll minpos = 0;
    ll s = LONG_LONG_MIN, e = LONG_LONG_MAX;
    while (e > s + 1) {  //find smallest possible y-value where it goes down
        ll m = (s + e) / 2;
        if (valid(m)) { s = m; }
        else { e = m; }
    }
    minpos = s;
    //okay now find that for our other side
    s = LONG_LONG_MIN, e = LONG_LONG_MAX;
    while (e > s + 1) {  //find smallest possible y-value where it goes down
        ll m = (s + e) / 2;
        if (valid2(m)) { e = m; }
        else { s = m; }
    }
    cout << e - minpos << "\n";
    //okay so we have that
    //and then we need to assign 4 cows to it
    //...the slopes are always integer
    //negatives can only shoot "down"
    //and for each target we need 
    //2 negatives and 2 positives
    //as long as we have that it is possible
    //wiat but cows cant be on the same thing
    //and finally we need to figure out the optimal placements
    //we should probably place the most extreme on the insides
    //and on the outsides place the least acute angles (or some math term)
    //check the sample
    //is there a way to binary search on this?
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}