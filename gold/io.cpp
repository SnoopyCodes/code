#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    vector<int> v{1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " \n"[i == v.size() - 1];
    }
    cout << "it worked" << "\n";
}