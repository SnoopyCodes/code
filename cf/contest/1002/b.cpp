#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    //indexing is hard
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int extra = N - K;
    vector<int> B;
    int at = 1;
    for (int i = 0; i < N;) {
        int cnt = 0;
        i++;  //put this element inside subarray
        while (i < N && A[i] == at) { i++; cnt++; }
        //we have a lot of these... things
        //assume we are at odd thing
        //see if we can force this time to be a by taking the rest
        if (cnt <= extra) { cout << at << "\n"; return; }
        if (cnt > 1 && extra) { cout << at + 1 << "\n"; return; }
        at++;
    }
    cout << at << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}