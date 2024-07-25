#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> moves;
int K;
vector<bool> is_even;
int get_min(int i) {
    //bessie will play the minimum value (least gain for elsie)
    int mn = INT_MAX;
    for (int j = 0; j < K; j++) {
        mn = min(moves[i][j], mn);
    }
    return mn;
}
int get_def(int i) {
    //bessie can play either max of odds or max of evens
    //elsie can choose either of them; choose the lesser one
    //wait
    //
    int oddmx = 0;
    int evmx = 0;
    for (int j = 0; j < K; j++) {
        if (moves[i][j] % 2) {
            oddmx = max(oddmx, moves[i][j]);
        }   else {
            evmx = max(evmx, moves[i][j]);
        }
    }
    if (oddmx > evmx) {  //choose odd, otherwise even
        is_even[i] = false;
    }
    //we play optimally
    return min(oddmx, evmx);
}
void solve() {
    int N, M; cin >> N >> M >> K;
    is_even.clear();
    moves.clear();
    moves.resize(M, vector<int>(K));
    is_even.resize(M, true);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> moves[i][j];
        }
    }
    vector<int> res(M);
    for (int i = 0; i < M; i++) {
        bool same = true;
        for (int j = 1; j < K; j++) {
            same &= ((moves[i][j] % 2) == (moves[i][0] % 2));
        }
        if (same) {
            //yes okay
            is_even[i] = (0 == moves[i][0] % 2);
            res[i] = get_min(i);  //is an increase supposedly
        }   else {
            res[i] = -get_def(i);  //is a decrease
        }
    }
    vector<int> suff_def(M); //the max deficit AFTER we play this move
    int rmin = 0;
    int rval = 0;
    for (int i = M - 1; i > -1; i--) {
        //armin
        suff_def[i] = rmin - rval;
        rval -= res[i];
        rmin = min(rmin, rval);
    }
    for (int i = 0; i < M; i++) {
        if (N <= 0) { cout << -1 << "\n"; return; }
        if (is_even[i]) { N += res[i]; continue; }
        int mx = 0;
        for (int j = 0; j < K; j++) {
            if (moves[i][j] % 2 == 1) {
                mx = max(moves[i][j], mx);
            }
        }
        if (N - mx + suff_def[i] > 0 && N - mx > 0) {
            is_even[i] = true;
            N -= mx;
        }   else {
            N += res[i];
        }
    }
    if (N <= 0) { cout << -1 << "\n"; return; }
    for (int i = 0; i < M; i++) {
        if (is_even[i]) { cout << "Even"; }
        else { cout << "Odd"; }
        cout << " \n"[i == M - 1];
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T) { T--; solve(); }
}