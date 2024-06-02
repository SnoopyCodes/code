#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    int r, c; cin >> r >> c;
    r--; c--;
    int cnt = (r > 0) + (r < N - 1) + (c > 0) + (c < M - 1);
    cout << cnt << "\n";
}