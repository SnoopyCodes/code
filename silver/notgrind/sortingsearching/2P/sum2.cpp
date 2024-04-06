#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, x;
    cin >> N >> x;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int l = 0, r = N - 1;
    bool found;
    while (l < r) {
        if (v[r] + v[l] > x) { r--; }
        else if (v[r] + v[l] < x) { l++; }
        else { found = true; break; }
    }
    cout << l+1 << " " << r+1;
}