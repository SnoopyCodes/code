#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }
    //this is like quite trivial or something
    sort(trees.begin(), trees.end());
    //just set a capacity limit on the number of berries we will ever collect
    //okay what if there is like more than that on one tree
    //uhhhhhhhh
    //wait uhh
    //we should try to fill up all of elsies baskets first
    //and then give the rest to bessie
    reverse(trees.begin(), trees.end());
    int ans = 0;
    for (int i = 1; i < 1001; i++) {  //number of berries per basket for elsie
        vector<int> tmp = trees;
        int cnt = 0;
        int baskets = 0;
        for (int j = 0; j < N; j++) {
            if (baskets == K / 2 || tmp[j] < i) { break; }
            while (baskets < K / 2 && tmp[j] >= i) { tmp[j] -= i; baskets++; }
        }
        if (baskets < K / 2) { break; }  //doesn't work anymore
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        baskets = 0;
        for (int j = 0; j < N; j++) {
            if (baskets == K / 2) { break; }
            //bruh
            cnt += tmp[j];
            baskets++;
        }
        //i know now how to do it i will just not do it
        ans = max(cnt, ans);
    }
    cout << ans << "\n";
}