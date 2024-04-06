#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N; cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    stable_sort(v.begin(), v.end());
    int maxd = 0;
    for (int i = 0; i < N; i++) {
        maxd = max(maxd, v[i].second - i);
    }
    cout << maxd+1 << "\n";
    /*
    if it is sorted after the swap, we don't find out until the next iteration
    okay then
    in that case i have no clue what to do
    each iteration, it carries the maximum of each subarray to the front of the subarray
    so it takes like the number htat are smaller before to get in line
    each thing that is larger htan it is supposed to be can only go down 1 at a time though
    so we just sort and check the distance from where it should be
    however what if theyre the same
    mergesort
    */
}