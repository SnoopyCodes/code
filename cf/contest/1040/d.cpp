#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;


void solve() {
    int N; cin >> N;
    vt<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    /*
    try greedy??
    make # of inversions # with ind < num > and ind > num <
    */

    vt<int> inv(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < i) {
                inv[i] += P[j] > P[i];
            }   else if (i < j) {
                inv[i] += P[i] > P[j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int ind = max_element(inv.begin(), inv.end()) - inv.begin();
        int d = 0;
        for (int j = 0; j < N; j++) {
            if (j < i && P[ind] < P[j] && P[j] < 2 * N - P[ind]) {
                d++;
            }
            if (i < j && P[ind] < P[j] && P[j] < 2 * N - P[ind]) {
                d--;
            }
        }
        if (d > 0) {
            for (int j = 0; j < N; j++) {
                if (j < i && P[ind] < P[j] && P[j] < 2 * N - P[ind]) {
                    inv[j]--;
                }
                if (i < j && P[ind] < P[j] && P[j] < 2 * N - P[ind]) {
                    inv[j]++;
                }
            }
            P[ind] = 2 * N - P[ind];
            inv[ind] = -N;
        }
    }
    int ct = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ct += P[j] < P[i];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << P[i] << " \n"[i == N - 1];
    }
    cout << ct << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}