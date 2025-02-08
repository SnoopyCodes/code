#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, W; cin >> N >> W;
    vec<arr<int, 3>> block(N, {-1, -1, (int) 1e9 + 1});  //time of erasure
    vec<vec<arr<int, 2>>> col(W);
    for (int i = 0; i < N; i++) {
        cin >> block[i][0] >> block[i][1];
        block[i][0]--; block[i][1]--;
        col[block[i][0]].push_back({block[i][1], i});
    }

    bool can = true;
    for (int i = 0; i < W; i++) {
        sort(col[i].begin(), col[i].end());
        reverse(col[i].begin(), col[i].end()); //have to use like a stack
        can &= !col[i].empty();
    }
    int time = 0;  //time of last erasure
    while (can) {
        int wait = 0;  //waiting time until it is all in alignment
        for (int i = 0; i < W; i++) {
            can &= col[i].size() > 1;
            wait = max(col[i].back()[0] - time, wait);
        }
        for (int i = 0; i < W; i++) {
            block[col[i].back()[1]][2] = time + wait + 1;
            col[i].pop_back();
        }
        time += wait + 1;
    }
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t, i; cin >> t >> i; i--;
        if (block[i][2] > t) { cout << "Yes" << "\n"; }
        else { cout << "No" << "\n";}
    }
}