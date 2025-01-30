#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> appear(N);
    long total = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        total += (long) (i + 1) * (N - i);
        appear[x].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        int last = -1;
        for (int j = 0; j < (int) appear[i].size() - 1; j++) {
            total -= (long) (appear[i][j] + 1) * (N - appear[i][j + 1]);
            last = appear[i][j];
        }
    }
    for (int i = 0; i < N - 1; i++) {
        vector<int> cur = appear[i];
        vector<int> nxt = appear[i + 1];
        if (cur.empty() || nxt.empty()) { continue; }
        //for l, r, count subarrays for which they matter
        //but count closest 
        //iterate through (nxt, cur) points
        //find, for cur, the closest left and right points
        //let the bounds in which it applies be like
        //wait first of all why is this wrong
        for (int j = 0; j < cur.size(); j++) {
            int k = upper_bound(nxt.begin(), nxt.end(), cur[j]) - nxt.begin();
            if (k == nxt.size()) { continue; }
            if (j < cur.size() - 1 && cur[j + 1] < nxt[k]) { continue; }
            int l = -1;
            if (k > 0) { l = nxt[k-1]; }
            total -= (long) (cur[j] - l) * (N - nxt[k]);
        }
        for (int j = 0; j < nxt.size(); j++) {
            int k = upper_bound(cur.begin(), cur.end(), nxt[j]) - cur.begin();
            if (k == cur.size()) { continue; }
            if (j < nxt.size() - 1 && nxt[j + 1] < cur[k]) { continue; }
            int l = -1;
            if (k > 0) { l = cur[k-1]; }
            total -= (long) (nxt[j] - l) * (N - cur[k]);
        }
    }
    cout << total << "\n";
}