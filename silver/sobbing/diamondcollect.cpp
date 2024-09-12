#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    //calculate for every single elemtn
    //the amounht we can store by choosing this as the smallest value
    //then we need to find the maximum sum of any 2 where they dont overlap
    //use suffix maxes
    vector<int> best(N);
    int l = 0, r = 1;
    for (; l < N; l++) {
        while (r < N && v[r] <= v[l] + K) { r++; }
        best[l] = r - l;
    }

    vector<int> suffmax(N);
    suffmax[N - 1] = best[N - 1];
    for (int i = N - 2; i > -1; i--) {
        suffmax[i] = max(suffmax[i + 1], best[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, best[i] + suffmax[min(i + best[i], N - 1)]);
    }
    cout << ans << "\n";
}