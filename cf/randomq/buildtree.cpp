#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, d12, d23, d31; cin >> N >> d12 >> d23 >> d31;
    //a + b <= c?
    //parities?
    if (min({d12, d23, d31}) + (d12+d23+d31-min({d12,d23,d31})-max({d12,d23,d31})) < max({d12,d23,d31}) || ((d12 ^ d23 ^ d31) & 1)) {
        cout << "NO" << "\n";
        return;
    }
    //obviously.
    //now we put the longest strand.
    //if the difference from there is not like even, then...
    vt<ii<2>> ans;
    int u = 4;
    //add d12 - 1 nodes
    //uhh we are solving what
    //d23 + d13 - d12 = 2 * extra dist (# nodes)
    //after d23 - extra dist nodes we add it?
    int rem = d23 + d31 - d12 >> 1;
    int lst = 2;
    bool done = false;
    if (d23 + d12 == d31) {
        int lstt = 2;
        for (int j = 0; j < rem - 1; j++) {
            int v = u;
            ans.push_back({ lstt, v });
            lstt = v;
            u++;
        }
        done = true;
        ans.push_back({ lstt, 3 });
    }

    for (int i = 0; i < d12 - 1; i++) {
        if (d12 == d31 + d23 && i == d23 - rem - 1 && !done) {
            done = true;
            ans.push_back({ 3, lst });
            lst = 3;
            continue;
        }
        int v = u;
        ans.push_back({ lst, v });
        lst = v;
        u++;
        if (i == d23 - rem - 1 && !done) {
            int lstt = lst;
            for (int j = 0; j < rem - 1; j++) {
                int v = u;
                ans.push_back({ lstt, v });
                lstt = v;
                u++;
            }
            done = true;
            ans.push_back({ lstt, 3 });
        }
    }
    ans.push_back({ lst, 1 });
    if (!done) { //31 + 12 = 32
        int lstt = 1;
        for (int j = 0; j < rem - 1; j++) {
            int v = u;
            ans.push_back({ lstt, v });
            lstt = v;
            u++;
        }
        done = true;
        ans.push_back({ lstt, 3 });
    }
    while (u <= N) {
        ans.push_back({ 1, u++ });
    }
    if (size(ans) != N - 1) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    for (auto [u, v] : ans) {
        cout << u << " " << v << "\n";
    }


}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}