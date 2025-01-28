#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, L; cin >> N >> M >> L;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int s = 0, e = 1e9 + 1e5 + 1;
    while (s + 1 < e) { 
        int m = (s + e) / 2;
        int ops = 0;
        vector<int> end(N + 1);
        int inc = 0;
        for (int i = 0; i < N; i++) {
            inc -= end[i];
            int diff = max(0, m - (A[i] + inc));
            ops += diff;
            if (ops > M) { break; }
            end[min(N, i + L)] = diff;
            inc += diff;
        }
        if (ops <= M) { s = m; }
        else { e = m; }
    }
    cout << s << endl;
}