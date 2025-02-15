#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    vec<int> v(3); cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0] * v[1] == v[2]) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n"; }
}