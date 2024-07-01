#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    vector<int> appear(1e6+1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        appear[v[i]]++;
    }
    //find greatest gcd?
    int mx = 1;
    for (int i = 2; i < 1e6 + 1; i++) {
        int cnt = 0;
        for (int j = i; j < 1e6 + 1; j += i) {
            cnt += appear[j];
        }
        if (cnt > 1) { mx = i; }
    }
    cout << mx << "\n";
}