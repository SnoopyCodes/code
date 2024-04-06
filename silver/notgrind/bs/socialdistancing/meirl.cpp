#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll, ll>> intervals;
int N;
bool works(ll d) {
    int dN = N;
    int ival = 0;
    ll lasti = -d;
    while (dN != 0) {
        if (ival == intervals.size()) { return false; }
        while (ival != intervals.size() && lasti + d > intervals[ival].second) {
            ival++;
        }
        if (ival == intervals.size()) { return false; }
        lasti = max(lasti + d, intervals[ival].first);
        dN--;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int M; cin >> N >> M;
    intervals.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    //this is really simple: binary search a value of d, and then greedily set cows as close together as d allows
    ll r = 1e18+1, l = 1;
    int count = 0;
    while (r - 1 >= l) {
        count++; if (count == 200) { break; }
        ll m = (l+r) / 2;
        if (works(m)) { l = m; }
        else { r = m; }
    }
    cout << l;
}