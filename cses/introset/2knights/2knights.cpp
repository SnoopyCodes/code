#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for (long long i = 1; i <= N; i++) {
        cout << (i * i * (i * i - 1)) / 2 - (i - 1) * (i-2) * 4 << "\n";
    }
}