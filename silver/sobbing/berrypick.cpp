#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int N, K; cin >> N >> K;
    //so
    //for this patch what do we do
    //so uh the key is to find the maximum berries in a basket
    //and work from there
    //is this function monotonic?
    //ehh not really we should iterate through everything
    //then just fill everything and sort and ??? this is not that bad
    //i guess once you know the solution...
    //but often its just about finding the right way to look at the problem i guess
    //consider multiple perspectives!
    vector<int> berries(N);
    for (int i = 0; i < N; i++) {
        cin >> berries[i];
    }
    int ans = 0;
    for (int maxb = 1; maxb <= 1000; maxb++) {
        vector<int> remain(K);  //pad with empty elements
        int num = 0;
        for (int i = 0; i < N; i++) {
            num += berries[i] / maxb;
            remain.push_back(berries[i] % maxb);
        }
        int res = 0;
        
        for (int i = 0; i < num && i < K; i++) {
            remain.push_back(maxb);
        }
        sort(remain.begin(), remain.end());
        reverse(remain.begin(), remain.end());
        for (int i = K / 2; i < K; i++) {
            res += remain[i];
        }
        ans = max(res, ans);
    }
    cout << ans << "\n";
}