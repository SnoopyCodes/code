#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> forest(N);
    vector<array<int, 3>> laws(K);
    for (int i = 0; i < N; i++) {
        cin >> forest[i];
    }
    sort(forest.begin(), forest.end());
    vector<vector<int>> um(N + 1);
    for (int i = 0; i < K; i++) {
        cin >> laws[i][0] >> laws[i][1] >> laws[i][2];
        laws[i][0] = lower_bound(forest.begin(), forest.end(), laws[i][0]) - forest.begin();
        laws[i][1] = upper_bound(forest.begin(), forest.end(), laws[i][1]) - forest.begin();
        laws[i][2] = laws[i][1] - laws[i][0] - laws[i][2];
        um[laws[i][0]].push_back(i);
    }
    set<array<int, 2>> mins;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        while (!mins.empty() && (*mins.begin())[0] <= i) {
            mins.erase(mins.begin());
        }
        for (int x : um[i]) {
            int r = laws[x][1];  //right bound
            int lim = laws[x][2];  //number we can cut
            int amt = lim + cur;  //total cut number at the end
            bool valid = true;
            if (!mins.empty()) {  //if there are any constraints stricter than us dont add
                auto it = mins.lower_bound({r, 0});
                if (it != mins.end() && amt >= (*it)[1]) {
                    valid = false;
                }
                if (it != mins.begin()) {
                    --it;
                    auto stop = mins.begin();
                    while (it != stop && (*it)[1] >= amt) {
                        it = mins.erase(it);
                        --it;
                    }
                    if (it == stop && (*it)[1] > amt) { mins.erase(it); }
                }
            }
            if (valid) { mins.insert({r, amt}); }
        }
        if (mins.empty() || (*mins.begin())[1] > cur) {
            cur++;
        }
    }
    cout << cur << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T = 0;  cin >> T; while (T--) { solve(); }
}