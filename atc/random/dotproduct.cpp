#include <bits/stdc++.h>

using std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;
template<class T> using list = std::vector<T>;

void solve() {
    int N; std::cin >> N;
    list<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    //idea: the closer together the 2 numbers are in terms of division
    //the less useful it is.
    //find two pairs where A_i / B_i is max, and A_i / B_i is min
    //(pos) ai bi aj bj (neg)
    //if ai < aj multiply it up to aj
    auto greater = [&](int x, int y) {
        return (long) A[x] * B[y] > (long) A[y] * B[x];
    };
    int mini_r = 0, maxi_r = 0;
    list<int> ans(N);
    for (int i = 1; i < N; i++) {
        if (greater(mini_r, i)) { mini_r = i; }
        if (greater(i, maxi_r)) { maxi_r = i; }
    }
    if (A[mini_r] > A[maxi_r]) {
        int r = (A[mini_r] + 1 + A[maxi_r] - 1) / A[maxi_r];
        ans[maxi_r] = r;
        ans[mini_r] = -1;
    }   else if (B[maxi_r] > B[mini_r]) {
        int r = (B[maxi_r] + 1 + B[mini_r] - 1) / B[mini_r];
        ans[mini_r] = -r;
        ans[maxi_r] = 1;
    }   else {
        ans[mini_r] = -1;
        ans[maxi_r] = 1;
    }
    bool f = true;
    int test = A[mini_r] * ans[mini_r] + A[maxi_r] * ans[maxi_r];
    f &= test > 0;
    test = B[mini_r] * ans[mini_r] + B[maxi_r] * ans[maxi_r];
    f &= test < 0;
    if (f) {
        std::cout << "Yes" << "\n";
        for (int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
    }   else { std::cout << "No" << "\n"; }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}