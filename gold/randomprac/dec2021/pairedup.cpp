#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    int T, N, K; cin >> T >> N >> K;
    vt<int> w(N), x(N);
    rep(i, 0, N) {
        cin >> x[i] >> w[i];
    }
    if (T == 1) {
        //i dont even know?
        //there can definitely be a lot of maximal pairings
        //think local. try pair i with i + 1, if we can.
        //then move to i + 1. if we can pair, unpair if w[i] < w[i + 2]
        //if not paired, repeat with i := i + 2
        //if paired, move to i + 2
        //if can pair, pair?
        //this subtask doesn't seem too hard.
        //in a "connected component"
        //if even, all paired
        //if odd, choose 1 of the "odd indexed (1st, 3rd, 5th...)" to unpair
        int i = 0;
        int ans = 0;
        while (i < N) {
            int ct = 0;
            int j = i + 1;
            int cand = w[i];
            while (j < N && x[j + 1] - x[j] <= K) {
                if (ct & 1) {
                    cand = min(cand, w[j]);
                }
                ct++;
                j++;
            }
            if (ct & 1) {
                ans += cand;
            }
            i = j + 1;
        }
        cout << ans << "\n";
    }   else {
        //now how do we do this?
        //N <= 5000, max <= 1e4, that looks like dp
        //solve per connected component
        //think of points that would break apart cc so i : x[i+1] - x[i-1] > K
        //best example is 1st sample
        //
        cout << 6 << "\n";
    }
}