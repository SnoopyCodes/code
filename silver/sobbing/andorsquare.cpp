#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> bits(20);
    
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        for (int j = 0; j < 20; j++) {
            if (k & 1 << j) { bits[j]++; }
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int k = 0;
        for (int j = 0; j < 20; j++) {
            if (bits[j] > 0) { k |= 1 << j; bits[j]--; }
        }
        ans += (long long) k * k;
    }
    cout << ans << "\n";
}