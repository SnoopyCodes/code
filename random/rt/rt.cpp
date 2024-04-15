#include <bits/stdc++.h>

using namespace std;
vector<array<int, 2>> pts;
vector<double> coeff;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    coeff.resize(N);
    pts.resize(N-1);
    for (int i = 0; i < N - 1; i++) {
        cin >> pts[i][0] >> pts[i][1];
    }
    sort(pts.begin(), pts.end());
    //basically, convert a polynomial from point form to default form
    //take it in from left to right
    //help how tf


    cout << fixed;
    cout << setprecision(2);
    for (int i = N-1; i >= 0; i--) {
        cout << coeff[i] << " ";
    }
    cout << "\n";
}