#include <bits/stdc++.h>

using namespace std;
// using ll = long long;
#define int long long

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //add active queries based on left ep
    //remove on right
    //couldn't we do a lazy segtree cheese?
    //essentially: select 2 endpoints
    //find for each subarray with those endpoints how many work
    //then we need to perform sums
    vector<int> alive(4e6 + 1);
    int boost = 2e6;
    vector<vector<int>> ep(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        int need = -A[i];
        for (int j = i + 2; j < N; j++) {
            need -= A[j];
            alive[A[j - 1] + boost]++;
            ep[i][j] = alive[need + boost];
            need += A[j];
        }
        for (int j = i + 2; j < N; j++) {
            alive[A[j - 1] + boost]--;
        }
    }
    //we should now have the whole thing
    //within each subarray there are len^2 subarrays to add together
    //but we can speed it up if we only look at endpoints and build from smallest i think
    
    for (int len = 3; len < N; len++) {
        for (int i = 0; i < N - len; i++) {
            int r = i + len;
            ep[i][r] += ep[i + 1][r] + ep[i][r - 1] - ep[i + 1][r - 1];
        }
    }
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r; l--; r--;
        cout << ep[l][r] << "\n";
    }

}