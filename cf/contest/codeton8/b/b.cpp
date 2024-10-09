#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> P(N);
    vector<bool> found(N+1);
    int mex = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        //A[i] = MEX (P[0]...P[i]) - P[i]
        //if mex - A[i] = P[i] 
        //but then P[i] found < 0 or is already found
        //then mex is invalid; P[i] = mex
        //hold on
        //i think so
        if (mex - a < 0 || found[mex - a]) {
            found[mex] = true;
            while (found[mex]) { mex++; }
            found[mex - a] = true;
            cout << mex - a;
            if (i != -1) { cout << " "; }
        }   else {
            //business as usual
            cout << mex - a;
            found[mex - a] = true;
            if (i != -1) { cout << " "; }
        }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { solve(); T--; }
}