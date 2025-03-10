#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    set<int> s{2, 3, 4};
    cout << (s.lower_bound(5) == s.end()) << "\n";
}