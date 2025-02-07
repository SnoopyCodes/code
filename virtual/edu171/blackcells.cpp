#include <bits/stdc++.h>
#define long int64_t
#define vec vector

using namespace std;

void solve() {
    //bruh
    int N; cin >> N;
    vec<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //in sorted order
    //at most one cell not in list can be painted black
    //select a cell to pair with
    //the solution is to choose adjacent stuff
    //and do that
    //why is b <= 2000?
    //idk just send it
    //ok start thinking
    //wait for even N you cannot use any other
    //so the optimal solution should be 
    //binary search on it
    //go to the furthest possible
    //very much screw this
    //ok hold on
    //if we have even
    //what is the strategy
    //it is optimal to take the first 2, then the next two, etc.
    //otherwise ?
    //
    long ans = 2e18;
    if (N == 1) { cout << 1 << "\n"; return; }
    for (int i = 0; i < N; i++) {
        vec<long> cur;
        for (int j = 0; j < N; j++) {
            if (N % 2 == 0 || i != j) {
                cur.push_back(A[j]);
            }
        }
        //now an even case
        //find the minimum
        long most = 0;
        for (int j = 0; j < cur.size(); j += 2) {
            most = max(most, cur[j + 1] - cur[j]);
        }
        ans = min(ans, most);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}