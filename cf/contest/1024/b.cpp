#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] = abs(A[i]);
    }
    //ok
    //count number > A[0]
    int more = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[0]) { more++; }
    }
    //if more > N / 2 then yay
    //oops
    //make all abs
    //
    if (more >= (N - 1) / 2) {
        cout << "YES" << "\n";
    }   else {
        cout << "NO" << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}