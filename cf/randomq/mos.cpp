#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt grid(N, vt(N, 0));
    int e = 2, o = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                //find closer axis
                int cd = abs(N / 2 - j);
                int rd = abs(N / 2 - i);
                int d = rd;
                if (cd < rd) {
                    d = cd;
                }
                if (d % 2 == 0) {
                    grid[i][j] = o;
                    o += 2;
                }   else {
                    grid[i][j] = e;
                    e += 2;
                }
            // if (grid[i][j] < 10) { cout << 0;}
            cout << grid[i][j] << " \n"[j == N - 1];
        }
    }
}