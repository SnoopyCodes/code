#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "w", stdout);
    int T = 20;
    cout << T << "\n";
    for (int t = 0; t < T; t++) {
        // int N = 1000;
        // cout << N << "\n";
        // //limit is 50 per, break to give a "worst case" case
        // cout << 918 << "\n";
        // for (int i = 1; i < N; i++) {
        //     cout << 38 << "\n";
        // }
        int N = 64;
        cout << N << "\n";
        // cout << 18 << "\n";
        // for (int i = 1; i < N; i++) {
        //     cout << 50 << "\n";
        // }
        for (int i = 0; i < N; i++) {
            cout << rand() % 50 + 1 << "\n";
        }
    }
}