#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    int sum; cin >> sum;
    //2p is annoying
    //oh no repeated numbers
    //wait then this is significantly simpler
    int l = 0, r = N - 1;
    while (l < r) {
        while (l < r && A[l] + A[r] > sum) { r--; }
        if (l >= r) { continue; }
        if (A[l] + A[r] == sum) { ans++; }
        l++;
    }
    cout << ans << "\n";
}