#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
const int N = 2e6 + 5;
int freq[N], suff[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //i forgot how to stone game, but since its a cool problem, im redoing it
    int n; cin >> n;
    int maxv = 0;
    rep(i, 0, n) {
        int x; cin >> x; freq[x]++;
        maxv = max(maxv, x);
    }
    int ans = 0;
    for (int i = maxv; i > 0; i--) {
        suff[i] += suff[i + 1] + freq[i];
        int ct_odd = 0;
        int odd = 0;
        vt<int> vals;
        vt<int> inds;
        for (int j = i; j <= maxv; j += i) {
            int range = suff[j] - suff[j + i];
            inds.add(j);
            vals.add(range & 1);
        }
        /*
        legal if start is only odd, or there is only 2 consecutive odds
        */

        int j = find(begin(vals), end(vals), 1) - begin(vals);
        if (j == size(vals)) {
            continue;
        }
        int ct = count(begin(vals), end(vals), 1);
        if (ct == 1 && j == 0) {
            ans += suff[inds[j]] - suff[inds[j] + i];
        }   else if (ct == 2 && j < (int) size(vals) - 1 && vals[j + 1] == 1) {
            ans += suff[inds[j + 1]] - suff[inds[j + 1] + i];
        }
    }
    cout << ans << "\n";



}