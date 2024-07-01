#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    vector<int> v(N);
    vector<int> vpfx(N+1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++) {
        vpfx[i+1] = vpfx[i] ^ v[i];
    }
    for (int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b;
        cout << (vpfx[b] ^ vpfx[a-1]) << "\n";
    }
}