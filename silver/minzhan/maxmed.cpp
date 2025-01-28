#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //iirc its just bs on largest median
    //for some median, there must be (K - 1) / 2 elements >= it?
    //length K maintain sliding window and pop/push elements good work
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int s = 0, e = N + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        bool valid = false;
        //we want to find a length >= K subarray that has positive sum
        //set 1, -1's
        //suppose we want to find for some right bound i if it is possible
        //im guessing maximum subarray sum works?
        vector<int> pf(N + 1);
        for (int i = 1; i <= N; i++) {
            int v = A[i - 1] >= m ? 1 : -1;
            pf[i] = pf[i-1] + v;
        }
        //distance k away
        int least = N;
        for (int i = 1; i <= N; i++) {
            if (i >= K) { least = min(least, pf[i - K]); }
            valid |= pf[i] - least > 0;
        }
        if (valid) { s = m; }
        else { e = m; }
    }
    //notes: good problem on max subarray sum and binary search
    //implementation very slow..
    //I had attempted this problem before so I knew the general idea
    //(for max/min median, binary search, and at least half the elements are <= or >= itself)
    //but came up with +1 and -1 and max subarray sum idea on my own
    cout << s << "\n";
}