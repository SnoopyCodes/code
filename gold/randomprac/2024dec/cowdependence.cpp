#include <bits/stdc++.h>

using namespace std;
//If you just brute force w/ binary search it passes, no grouping needed as in edi
//pretty stupid problem, but funny

//solve independently for each label.
//while the groups (g) > 1, binary search on min size to change # cc
//use difference arrays to construct final answer

//# changes in g are bounded by 2 * sqrt(M)
//counting changes w/ all 1's shows this.
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> label(N);
    vector<vector<int>> appear(N);
    for (int i = 0; i < N; i++) {
        cin >> label[i]; label[i]--;
        appear[label[i]].push_back(i);
    }
    vector<int> groups(N + 1);
    vector<int> diff(N + 2);
    for (int i = 0; i < N; i++) {
        vector<int> cur = appear[i];
        int M = cur.size();
        int g = M;
        if (g == 0) { continue; }
        int lst = 0;
        while (g > 1) {
            int s = lst, e = N;
            int res = -1;
            while (s + 1 < e) {
                int m = (s + e) / 2;
                int now = 0;
                //form groups
                int last = -1;
                for (int i = 0; i < M; i++) {
                    if (last >= cur[i]) { continue; }
                    now++;
                    last = cur[i] + m;
                }
                if (now >= g) { s = m; }
                else { e = m; res = now; }
            }
            //e is minimum size needed to change
            //thus the current amount ranges from lst to e
            diff[lst] += g;
            diff[e] -= g;
            g = res;
            lst = e;
        }
        diff[lst] += 1;
        diff[N + 1] -= 1;
    }
    int cur = diff[0];
    for (int i = 1; i <= N; i++) {
        cur += diff[i];
        cout << cur << "\n";
    }
}