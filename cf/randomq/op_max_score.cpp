#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N, K; std::cin >> N >> K;
    vector<ints<2>> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i][0];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> A[i][1];
    }
    std::sort(A.begin(), A.end());
    // for (int i = 0; i < N; i++) {
    //     std::cout << A[i][0] << " " << A[i][1] << "\n";
    // }
    int big_med = A[(N - 2) / 2][0];
    int small_med = A[N / 2][0];  //if we take and we are <= (N - 2) / 2


    /*
    for b_i = 1, ans = max(ans, a_i + k + median)
    b_i = 0? increase median
    */
    
    /*
    prove that maximizing the median maximizes it for deletion of stuff
    if we delete elements <= median, the median goes up. so actually, 
    we only need to increase elements past the median.
    wait i am highly regarded because we will never choose smaller element
    so we only need to deal with the one case of OK ez
    */
//    std::cout << small_med << " " << big_med << "\n";
    auto C = A;
    //for "m" to be median, we need (N+2) / 2 elements >= it
    int s = 0, e = 2 * BIG;
    while (s + 1 < e) {
        int m = s + (e - s) / 2;
        int k = K, ct = 0;
        for (int i = N - 1; i > -1; i--) {
            if (C[i][0] >= m) { ct++; }
            else if (C[i][1]) {
                int diff = m - C[i][0];
                if (k < diff) {
                    break;
                }   else {
                    k -= diff;
                    ct++;
                }
            }
        }
        if (ct >= (N + 1) / 2 + 1) { s = m; }
        else { e = m; }
    }
    //s is new possible median
    // std::cout << s << "\n";
    long ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i][1]) {
            if (i <= (N - 2) / 2) {
                ans = max(ans, (long) small_med + K + A[i][0]);
            }   else {
                ans = max(ans, (long) big_med + K + A[i][0]);
            }
        }
        ans = max(ans, (long) A[i][0] + s);
    }
    std::cout << ans << "\n";
    
    
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}