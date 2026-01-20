#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //the main problem is K?
    //if we have a K, then the problem is likely easy to solve. 
    //can we set K arbitrarily above N?
    //try to solve subtask first. 
    //i think placing from the back is wrong, totally wrong.
    //brute force for the subtask?
    //so, for i, find the first j that has a_j >= i?
    //then, we are in the range [pos[j - 1] + 1 + K, pos[j] + K]?
    //
    int N; cin >> N;
    vt<int> A(N);
    rep(i, 0, N) {
        cin >> A[i], A[i]--;
    }
    rep(K, 1, 2 * N + 1) {
        vt<int> pos(N);
        pos[0] = 1;
        bool ok = true;

        if (ok) {
            cout << K << "\n";
            rep(i, 0, N) {
                cout << pos[i] << "\n";
            }
            break;
        }
    }

}