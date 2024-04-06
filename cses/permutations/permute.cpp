#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    if (N == 1) { cout << 1; return 0; }
    if (N <= 3) { cout << "NO SOLUTION"; return 0; }
    if (N == 4) {
        cout << "3 1 4 2";
        return 0;
    }
    for (int i = 1; i <= N; i += 2) {
        cout << i << " ";
    }
    for (int i = 2; i <= N; i += 2) {
        cout << i;
        if (i != N && i != N-1) { cout << " "; }
    }
}