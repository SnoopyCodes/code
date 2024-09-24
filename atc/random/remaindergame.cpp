#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //first: is modulo associative?
    //17 mod 7 mod 3 = 0
    //17 mod 3 mod 7 = 2
    //no
    //also, if we ever make
    //any a[i] < b[i], it is cooked!
    //so something that constructs a sequence
    //is iterating through which ones will
    //
    //wait
    //i think we should go from largest modulos to small ones
    //this much is obvious
    //8 cannot become 5. why is that?
    //bc (8-5) < (5+1)
    //we can try to start from the least cost

    //ok what i miss is:
    //yes go downwards, but we can construct the integer
    //by checking if it is possible to form without the mod in question
    //if not, then mod each value by it .?
    //and fix it in there
    //then move on
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    long long res = 0;
    const int mx = 51;
    int x = 2;
    x |= mx;
    vector<int> s;
    for (int k = mx; k > 0; k--) {  //lmfao
        vector<vector<bool>> canmove(mx, vector<bool> (mx));
        for (int d = 1; d < k; d++) {
            for (int u = 0; u < mx; u++) {
                canmove[u][u % d] = true;
            }
        }
        for (int x : s) {
            for (int u = 0; u < mx; u++) {
                canmove[u][u % x] = true;
            }
        }
        for (int i = 0; i < mx; i++) {
            canmove[i][i] = true;
        }
        //graph formed, now we need to see
        //if it is possible for each one to get where it needs to
        for (int w = 0; w < mx; w++) {
            for (int i = mx - 1; i > 0; i--) {
                for (int j = i - 1; j > -1; j--) {
                    canmove[i][j] = canmove[i][j] | (canmove[i][w] && canmove[w][j]);
                }
            }
        }
        bool possible = true;
        for (int i = 0; i < N; i++) {
            if (!canmove[A[i]][B[i]]) {
                // cout << k << " " << A[i] << "\n";
                possible = false;
                s.push_back(k);
                break;
            }
        }
        if (!possible && k == mx) { cout << -1 << "\n"; return 0; }
        if (!possible) {
            res |= 1LL << k;
        }
    }
    cout << res << "\n";
}