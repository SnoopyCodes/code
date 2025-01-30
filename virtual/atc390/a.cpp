#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }
    bool yes = false;
    for (int i = 0; i < 4; i++) {
        int j = i + 1;
            swap(A[i], A[j]);
            bool valid = true;
            for (int k = 0; k < 4; k++) {
                if (A[k] > A[k + 1]) { valid = false; break; }
            }
            swap(A[i], A[j]);
            yes |= valid;
    }
    if (yes) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n";}
}