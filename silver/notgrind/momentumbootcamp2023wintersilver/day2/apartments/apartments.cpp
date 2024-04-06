#include <bits/stdc++.h>

using namespace std;
vector<int> desired;
vector<int> reality;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m, k; cin >> n >> m >> k;
    desired.resize(n);
    reality.resize(m);
    for (int i = 0; i < n; i++) { cin >> desired[i]; }
    sort(desired.begin(), desired.end());
    for (int i = 0; i < m; i++) { cin >> reality[i]; }
    sort(reality.begin(), reality.end());
    int i = 0, j = 0;
    int c = 0;
    while (i != n && j != m) {
        if (desired[i] >= reality[j] - k && desired[i] <= reality[j] + k) {
            c++;
            i++; j++;
        }   else if (desired[i] < reality[j] - k) { i++; }
        else if (desired[i] > reality[j] + k) { j++; }
    }
    cout << c << "\n";

}