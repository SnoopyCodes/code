#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N = 1000;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 1000000000;
    }
    sort(v.begin(), v.end());
    bool yes = true;
    //find last element less than
        int a = rand() % N;
        int x = v[a] + 1;
        int s = 0, e = N;
        while (e > s + 1) {
            int m = (s + e) / 2;
            if (v[m] >= x) { e = m; }
            else { s = m; }
        }
        if (s != a) { yes = false; }
    cout << yes << "\n";
}