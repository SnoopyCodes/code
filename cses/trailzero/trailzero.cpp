#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int total = 0;
    while (N > 0) {
        N /= 5;
        total += N;
    }
    cout << total << "\n";
}