#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<bool> here(N+1);
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        here[a] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (here[i] == false) { cout << i << "\n"; return 0; }
    }
}