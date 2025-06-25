#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const int INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;


void solve() {
    int N; std::cin >> N;
    vector<int> A(N);
    //bob always colors the last.
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    /*
    A[i] + A[j] + A[k] > A[N - 1]
    A[i] + A[j] > A[k]
    iterate on upper and lower bounds?
    yes
    */
    int ct_pt = 0;
    long ans = 0;
    for (int i = 0; i < N; i++) {  //up
        for (int j = 0; j < i; j++) {  //low
            //find ok mid
            int s = j, e = i;
            while (s + 1 < e) {
                int m = (s + e) / 2;
                if (A[i] + A[j] + A[m] > A[N - 1] && A[j] + A[m] > A[i]) {
                    e = m;
                }   else {
                    s = m;
                }
            }
            ans += i - e;
        }
    }
    std::cout << ans << "\n";

}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}