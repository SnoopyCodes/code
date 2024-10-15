#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    ll ans = 0;
    vector<array<int, 2>> els(N);  //why did i name it this
    for (int i = 0; i < N; i++) {
        cin >> els[i][0];
    }
    for (int i = 0; i < N; i++) {
        cin >> els[i][1];
    }
    vector<array<int, 2>> diffs(1e6 + 1, {(int)1e9 + 1, 0});
    for (int i = 0; i < N; i++) {
        diffs[els[i][0]] = min(diffs[els[i][0]], {els[i][0] - els[i][1], els[i][0]});
    }
    for (int i = 1; i < 1e6 + 1; i++) {
        diffs[i] = min(diffs[i - 1], diffs[i]);
    }
    //i want to calculate the amount of xp for all values from 1... 1e6
    //find for each value the minimum "difference" that can occur, for as long as possible
    vector<ll> res(1e6 + 1);
    for (int i = 1; i < 1e6 + 1; i++) {
        if (diffs[i][0] == 1e9 + 1) { continue; }
        int amt = 1 + (i - diffs[i][1]) / diffs[i][0];
        int after = i - amt * diffs[i][0];
        res[i] = res[after] + amt;
    }
    for (int i = 0; i < M; i++) {
        int ingots; cin >> ingots;
        if (ingots > 1e6) {
            int amt = 1 + (ingots - diffs[1e6][1]) / diffs[1e6][0];
            ans += amt;
            ingots = ingots - amt * diffs[1e6][0];
        }
        ans += res[ingots];
    }
    ans *= 2;
    cout << ans << "\n";

}