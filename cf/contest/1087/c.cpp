#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
int query(int x, int y) {
    cout << "? " << x+1 << " " << y+1 << endl;
    cin >> x;
    if (x == -1) { exit(0); }
    return x;
}
void solve() {
    int N; cin >> N;
    vt<int> res(N);

    for (int i = 1; i < N; i++) {
        res[i] = query(i, 2 * N - i - 1);
        if (res[i]) {
            cout << "! " << i + 1 << endl;
            return;
        }
    }
    //we will use 1 and 2n, 2 and 2n - 1
    int r = query(0, 1);
    if (r) {
        cout << "! " << 1 << endl;
    }   else {
        r = query(0, 2 * N - 2);
        if (r) {
            cout << "! " << 1 << endl;
        }   else {
            cout << "! " << 2 * N << endl;
        }
    }
}

signed main() {
    int T; cin >> T; while (T --> 0) solve();
}