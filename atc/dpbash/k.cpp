#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<bool> win(K + 1);  //if the one moving wins
    for (int i = 0; i < K + 1; i++) {
        for (int j = 0; j < N; j++) {
            if (i - A[j] > -1) { win[i] = win[i] | !win[i - A[j]]; }
        }
    }
    cout << (win[K] ? "First" : "Second" )<< "\n";
}