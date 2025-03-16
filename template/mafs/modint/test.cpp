#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _v = 5;
    const int MOD = 7;
    int v = 3;
    v -= ((v += _v) > MOD) * MOD;
    cout << v << "\n";
}