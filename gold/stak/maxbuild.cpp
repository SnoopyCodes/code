#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //fix the base
    int N, M; cin >> N >> M;
    //if you think about it, doing prefix sums never hurts anyone
    //i hate 2d prefix sums tho
    //
    vector<queue<int>> cap(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            if (c == '*') {
                cap[i].push(j);
            }
        }
        cap[i].push(M);
    }
    int ans = 0;
    for (int base = 0; base < M; base++) {
        vector<int> height(N);
        for (int i = 0; i < N; i++) {
            if (base > cap[i].front()) { cap[i].pop(); }
            height[i] = cap[i].front() - base;
        }
        //now it is purely advertisement
        //iterate over and keep mono stack tracking less
        vector<int> areas = height;
        stack<array<int, 2>> less; less.push({-1, -1});
        auto calc = [&](bool flip) {
            for (int i = 0; i < N; i++) {
                while (height[i] <= less.top()[0]) { less.pop(); }
                int idx = flip ? N - 1 - i : i;
                areas[idx] += height[i] * (i - 1 - less.top()[1]);
                less.push({height[i], i});
            }
            while (!less.empty()) { less.pop(); }
            less.push({-1, -1});
        };
        calc(false);
        reverse(height.begin(), height.end());
        calc(true);
        ans = max(ans, *max_element(areas.begin(), areas.end()));
    }
    cout << ans << "\n";

}