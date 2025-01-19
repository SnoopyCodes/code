#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> arr(N);
    map<int, int> m;  //exist
    set<int> s;  //not exist
    for (int i = 0; i < N; i++) { s.insert(i); }
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        arr[i] = x;
        m[x]++;
        s.erase(x);
    }
    //if everything exists, then we just need to 
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 2) {
            int l, r; cin >> l >> r; l--; r--;
            if (!s.empty()) { cout << *s.begin() + 1 << "\n"; }
            else if (l > 0) { cout << arr[l-1] + 1 << "\n"; }
            else { cout << arr[r+1] + 1 << "\n"; }
        }   else {
            int i, y; cin >> i >> y; i--; y--;
            int x = arr[i];
            m[x]--;
            if (m[x] == 0) { s.insert(x); }
            m[y]++;
            arr[i] = y;
            s.erase(y);
        }
    }
    //if not then just output -1 or + 1
}