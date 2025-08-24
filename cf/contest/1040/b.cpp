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
    int N, S; cin >> N >> S;
    /*
    if S < sum(A) then no way.
    otherwise smth about parity?
    0 2 means it can't change parity however it wants.
    0 2 1 2 2 2 ...
    why is this freaking wrong bruh
    0 2 1 2 2 2 ....????
    0 2 1 cannot get to 8.
    wait it can. 7?
    A[1]?
    it can literally get to anything ????

    */
    vt<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int sum = accumulate(A.begin(), A.end(), 0);
    if (S < sum) {
        for (int i = 0; i < N; i++) {
            cout << A[i] << " \n"[i == N - 1];
        }
        return;
    }   else if (sum + 1 == S) {
        sort(A.begin(), A.end());
        int it = 0;
        while (A[it] == 0) { it++; }
        swap(A[it], A[N-1]);
        for (int i = 0; i < N; i++) {
            cout << A[i] << " \n"[i == N - 1];
        }
        return;
    }
    cout << -1 << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}