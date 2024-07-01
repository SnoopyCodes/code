#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> divs(1e6+1);
    for (int i = 1; i < 1e6 + 1; i++) {
        for (int j = i; j < 1e6 + 1; j += i) {
            divs[j]++;
        }
    }
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cout << divs[x] << "\n";
    }
}