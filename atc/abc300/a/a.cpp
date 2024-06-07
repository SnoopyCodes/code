#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A, B; cin >> N >> A >> B;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++) {
        if (v[i] == A + B) {
            cout << i+1 << "\n";
        }
    }
}