#include <bits/stdc++.h>

using namespace std;
bool visited[(int)1e7];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int max = pow(2, N);
    int cur = 0;
    visited[cur] = true;
    for (int i = 0; i < N; i++) {
        cout << 0;
    }
    cout << "\n";
    for (int i = 0; i < max-1; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[cur ^ 1 << j]) {
                cur ^= 1 << j;
                visited[cur] = true;
                break;
            }
        }
        for (int j = 0; j < N; j++) {
            cout << (bool) (cur & 1 << j);
        }
        cout << "\n";
    }
}