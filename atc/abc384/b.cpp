#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    int R; cin >> R;
    for (int i = 0; i < N; i++) {
        int d, a; cin >> d >> a;
        if (d == 1 && 1600 <= R && R <= 2799) { R += a; }
        else if (d == 2 && 1200 <= R && R <= 2399) { R += a; }
    }
    cout << R << "\n";
}