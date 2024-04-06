#include <bits/stdc++.h>

using namespace std;
vector<int> v;

void solve() {
    vector<int> copy = v;
    for (int k = 0; k < 8; k++) {
        bool allz = true;
        for (int i = 0; i < copy.size(); i++) { if (copy[i] != 0) { allz = false; break; } }
        if (allz == true) { break; }
        for (int i = 0; i < copy.size(); i++) {
            //brute forcing
            for (int j = i; j < )
        }
    }
    //10000 op, and order matters so 10000^8. not working.
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
    }
}