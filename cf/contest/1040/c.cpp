#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int N; cin >> N;
    vt<ints<2>> pairs(N);
    vv<ints<2>> G(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
        pairs[i][0]--; pairs[i][1]--;
        G[pairs[i][0]].push_back({ pairs[i][1], i });
    }
    /*
    there should never be a cycle?
    like never? so...
    okay, at every start point choose the longest.
    */
    vt<int> ans;
    for (int i = 0; i < 2 * N; i++) {
        if (G[i].empty()) { continue; }
        sort(G[i].begin(), G[i].end());
        ans.push_back(G[i][(int) G[i].size() - 1][1] + 1);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}