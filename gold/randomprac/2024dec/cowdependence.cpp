#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    auto beg = std::chrono::system_clock::now();
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
        int ct = 0;
        while (g > 1) { //changes in g are <= sqrt(M) * 2 and idk why
            //find the minimum size necessary to elicit a change in number of cc
            ct++;
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
        cout << ct << "\n";
        diff[lst] += 1;
        diff[N + 1] -= 1;
    }
    int cur = 0;
    for (int i = 0; i <= N; i++) {
        cur += diff[i];
        groups[i] = cur;
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << groups[i] << "\n";
    // }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - beg;
    cout << elapsed.count() << "\n";
}
//i have no idea why this works someone please help.