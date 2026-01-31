#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i!=(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    /*
    thank god for the cf era of no samples
    use a map, connect adjacent crap
    */

    map<int, int> m;
    rep(i, 0, N) {
        int x; cin >> x;
        m[x]++;
    }
    int ans = m.size();
    set<int> stretch_to;
    auto it = begin(m);
    while (it != end(m)) {
        int l = (*it).first;
        int cur = l;
        int amt = (*it).second;
        while (++it != end(m) && (*it).first == cur + 1) {
            cur++;
            amt += (*it).second;
        }
        //try placing on both sides
        //we range in [l, r]
        rep(z, 0, 2) if (amt-- > (cur - l + 1)) {
            if (l > 1 && !stretch_to.count(l - 1)) {
                stretch_to.insert(l - 1);
            }   else if (cur < 150001 && !stretch_to.count(cur + 1)) {
                stretch_to.insert(cur + 1);
            }
        }
    }
    cout << size(m) + size(stretch_to) << endl;
}