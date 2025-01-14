#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cout << fixed << setprecision(6);
    int N; cin >> N;
    vector<int> house(N);
    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    double eps = 1e-7;
    double s = 0, e = 1e9;
    while (s + eps < e) {
        double m = (s + e) / 2;
        int last = 0;
        int count = 1;
        for (int i = 1; i < N; i++) {
            if (house[i] > 2 * m + house[last]) { count++; last = i; }
        }
        if (count <= 3) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
    cout << house[0] + e << " ";
    int last = 0;
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (house[i] > 2 * e + house[last]) { last = i; cout << house[i] + e << " \n"[count == 2]; count++; }
    }
    while (count < 3) {
        cout << house[0] << " \n"[count == 2];
        count++;
    }

}