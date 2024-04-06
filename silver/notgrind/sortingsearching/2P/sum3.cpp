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
    //in a sorted array find 2 indexes whose values sum to an int x...
    sort(v.begin(), v.end());
    
    bool yay = false;
    for (int i = 0; i < N; i++) {
        int p = x - v[i];
        int l = 0, r = N - 1;
        bool found;
        while (l < r) {
            if (v[r] + v[l] > p) { r--; }
            else if (v[r] + v[l] < p) { l++; }
            else { found = true; break; }
        }
        if (found) { yay = true; break; }
    }
    
}