#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N; cin >> N;
    while (N != 1) {
        cout << N << " ";
        if (N % 2 == 0) { N /= 2; }
        else { N = N * 3 + 1; }
    }
    cout << 1 << "\n";
}