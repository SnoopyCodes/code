#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<int> A(N);
    vt<int> cl(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        int j = i - 1;
        while (j != -1 && A[i] <= A[j]) { j = cl[j]; }
        cl[i] = j;
        cout << j + 1 << " \n"[i == N - 1];
    }

}