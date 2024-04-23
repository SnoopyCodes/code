#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a {3, 5, 8};
    vector<int> b = a;
    a.erase(a.begin());
    for (int x : b) cout << x << "\n";
}