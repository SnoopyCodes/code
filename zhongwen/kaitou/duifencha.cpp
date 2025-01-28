#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for (int q = 0; q < Q; q++) {
        int x; cin >> x;
        cout << freq[x] << "\n";
    }
}