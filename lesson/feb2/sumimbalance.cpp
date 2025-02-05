#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

long cnt(vector<int> &v) {  //# of subarrays where this value doesn't appear
    if (v.empty()) { return 0; }
    long res = (long) v[0] * (v[0] + 1) / 2;
    for (int i = 0; i < v.size() - 1; i++) {
        int d = v[i + 1] - v[i];
        res += (long) d * (d - 1) / 2;
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    vector<vector<int>> appear(1e6 + 1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        appear[x].push_back(i);
    }
    //note that for a subarray, the imbalance of it
    //is eerily similar to atcoder 390 f, except -1 in each subarray
    //recap: for atcoder, for all subarrays, find the sum of number of operatoins
    //of the type [remove all subarray elements in range [l...r] such that [l...r] exist]
    //
    //it should be fairly simple to see how this is pretty much the same
    //in atcoder, the solution is: count for how many times an element value is 
    //used as a left bound. This is done iff i - 1 is not in the subarray, and 
    //i is in the subarray. to find when it is in a subarray, PIE is used:
    //# of subarrays where i - 1 DOES NOT appear, - # of subarrays where i AND i - 1
    //amazing problem, absolute cinema

    long ans = (long) -N * (N + 1) / 2;
    for (int i = 1; i <= 1e6; i++) {
        vector<int> cur = appear[i - 1];
        cur.push_back(N);
        ans += cnt(cur);
        for (int x : appear[i]) {
            cur.push_back(x);
        }
        sort(cur.begin(), cur.end());
        ans -= cnt(cur);
    }
    cout << ans % MOD << "\n";
}