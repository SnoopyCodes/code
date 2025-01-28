#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //trivial?
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> pf(N), sf(N);
    pf[0] = A[0], sf[N - 1] = A[N-1];
    for (int i = 1; i < N - 1; i++) {
        pf[i] = max(pf[i-1], A[i]);
        sf[i] = min(sf[i+1], A[i]);
    }
    int sum = 0;
    for (int i = 1; i < N - 1; i++) {
        if (pf[i-1] < A[i] && A[i] < sf[i+1]) { sum += 2; }
        else if (A[i-1] < A[i] && A[i] < A[i + 1]) { sum++; }
    }
    cout << sum << "\n";
}