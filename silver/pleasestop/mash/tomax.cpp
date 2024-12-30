#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    //binary search on max
    //then in order to perform the operation
    //wait let's just binary search on it and see if we can make it work
    //we want to force it to 
    vector<int> A(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ans = max(A[i], ans);
    }
    reverse(A.begin(), A.end());
    
    int s = 1, e = 2e8;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        int cnt = 0;
        //we want to attain a sequence starting from some value
        //x, x + 1, x + 2, etc. for as long as possible
        //x, x + 1, x + 2, ... for as long as possible
        //but do we?
        //start from some index and try to find the max we can increase it to?
        //how do we check if this is possible?
        //we can do this by letting some index be the "max" value
        //and then if it does not work, we walk backwards and see if any
        //work as a starting point
        bool valid = false;
        for (int i = 0; i < N; i++) {
            int rem = K;
            int found = -1;
            for (int j = i; j > -1; j--) {
                if (A[j] >= m - (i - j)) {
                    found = j;  //start from here
                    break;
                }
            }
            if (found == -1) { continue; }
            for (int j = found; j <= i; j++) {
                rem -= max(0, m- (i - j) - A[j]);
                if (rem < 0) { break; }
            }
            // if (m == 5 && rem >= 0) { cout << i << " " << rem << endl; }
            if (rem >= 0) { valid = true; break; }
        }
        if (valid) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}