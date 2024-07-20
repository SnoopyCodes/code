#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int R, G, B; cin >> R >> G >> B;
    string C; cin >> C;
    if (C[0] == 'R') {
        swap(R, B);
    }   else if (C[0] == 'G') {
        swap(G, B);
    }
    cout << min(R, G);
}