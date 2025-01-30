#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    bool yes = true;
    for (int i = 1; i < N - 1; i++) {
        if (A[i] * A[i] != A[i - 1] * A[i + 1]) {yes = false;}
    }
    if (yes) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n"; }
}