#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> lever; int temp;
    for (int i = 0; i < (n); i++) cin >> temp, lever.push_back(temp);
    int ones = 0, twos = 0;
    for (int i = 0; i < n; i++){
        if (lever[i] == 1) ones++;
        if (lever[i] == 2) twos++;
    }
    
    int totalOne = ones, totalTwo = twos * 2;int other = 0;
    if (totalOne + totalTwo % 2 == 1) { cout << "NO" << "\n"; return; }
    while (totalTwo > totalOne + other) { totalTwo -= 2; other += 2; }
    //now see if we can divide it equally
    if ((totalOne + totalTwo + other) / 2 - totalTwo > totalOne) {
        cout << "NO" << "\n"; return;
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}