#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> count(3);
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        count[x]++;
    }
    
}