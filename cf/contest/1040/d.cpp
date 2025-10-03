#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

#define test(a) a

void solve() {
    int N; cin >> N;
    vt<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    //look at the endpoints.
    //
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}