#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<array<int, 3>> posts;
bool comp(array<int,3> a1, array<int, 3> a2) {
    if (a1[1] == a2[1]) { return a1[0] < a2[0]; }
    return a1[1] < a2[1];
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N; cin >> N;
    posts.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> posts[i][0] >> posts[i][1];
        posts[i][2] = i;
    }
    vector<int> sumx(N);
    vector<int> sumy(N);
    //i really hope this is doable wtf
    //oh very crap we need areas
    //christ rip anyone who didnt promote the last contest holy crap
    //we need to calculate sum of heights from this point and sum of lengths from this point
    //transition from one point to another?
    sort(posts.begin(), posts.end());
    //sorted by x-components
    auto calc_sum = [&](int x) {
        vector<int> res(N);
        for (int i = 0; i < N; i++) {
            vector<int> cur;
            int o = i;
            cur.push_back(posts[i][!x]);
            while (i + 1 < N && posts[i][x] == posts[i+1][x]) { i++; cur.push_back(posts[i][!x]); }
            for (int j = 0; j < cur.size(); j++) {
                res[o] += cur[j] - cur[0];
            }
            for (int j = 1; j < cur.size(); j++) {
                int dist = cur[j] - cur[j-1];
                res[o + j] = res[o + j - 1] - dist * (cur.size() - j - (j));
            }
        }
        vector<int> real(N);
        for (int i = 0; i < N; i++) {
            real[posts[i][2]] = res[i];
        }
        return real;
    };
    const int MOD = 1e9 + 7;
    sumx = calc_sum(0);
    sort(posts.begin(), posts.end(), comp);
    sumy = calc_sum(1);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + (ll) sumx[i] * sumy[i]) % MOD;
    }
    cout << ans << "\n";
}