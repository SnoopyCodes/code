#include <bits/stdc++.h>

using namespace std;
vector<int> picture;
int M;
int LIS() {
    multiset<int> lis;
    //dp[i] = LIS for that segment
    //find for each
    vector<int> best(M);
    for (int i = 0; i < M; i++) {
        if (lis.upper_bound(picture[i]) != lis.end()) {
            cout << picture[i] << "\n";
            cout << *lis.upper_bound(picture[i]) << "\n";
            lis.erase(lis.find(*lis.upper_bound(picture[i])));
        }
        best[i] += lis.size();
        lis.insert(picture[i]);
    }
    for (int i = 0; i < M; i++) {
        cout << best[i] << " ";
    }
    cout << "\n";
    lis.clear();
    for (int i = 0; i < M / 2; i++) {
        swap(picture[i], picture[M - i - 1]);
    }
    for (int i = 0; i < M; i++) {
        if (lis.upper_bound(picture[i]) != lis.end()) {
            lis.erase(lis.find(*lis.upper_bound(picture[i])));
        }
        best[M - i - 1] += lis.size();
        lis.insert(picture[i]);
    }
    for (int i = 0; i < M / 2; i++) {
        swap(picture[i], picture[M - i - 1]);
    }
    return *max_element(best.begin(), best.end()) + 1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //one of those questions where one of the steps is formulating what it wants
    //obviously, if ask all points, know everything
    //if all points are the same, then no clue
    //if we have 2 1 2 at any time
    //then it is clear that there is not point belonging to all segment
    //so we want to find the largest monotonically increasing or decreasing segment
    //and use that length
    //not only that, this is LIS again
    int N; cin >> N >> M;
    picture.resize(M + 1);
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r; l--;
        picture[l]++;
        picture[r]--;
    }
    for (int i = 0; i < M; i++) {
        if (i > 0) { picture[i] += picture[i-1]; }
    }
    int ans = LIS();
    for (int i = 0; i < M; i++) { picture[i] = -picture[i]; }
    // ans = max(ans, LIS());
    cout << ans << "\n";
}