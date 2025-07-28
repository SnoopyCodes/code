#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

using vi = std::vector<int>;

vector<int> factor_naive(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) { continue; }
        if (n / i != i) { res.push_back(n / i); }
        res.push_back(i);
    }
    return res;
}

void solve() {
    int N; std::cin >> N;
    vi A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    /*
    N^2 log^2 is ok
    take all elements
    dont remove duplicates
    i think sort the array
    then the largest element is divided by all the other elements
    factorize numbers
    the second largest element cannot be divided by all the others?
    what if it is? pain and suffering, the answer is 0
    so say it is not
    then there is some number it is lcm'd with to make the large
    all the factors of this element
    bruh shoot you go over all the factors
    and that's it
    */
    std::sort(A.begin(), A.end());
    long lcm = 1;
    for (int i = 0; i < N; i++) {
        lcm = std::lcm(lcm, A[i]);
        if (lcm > A[N-1]) { break; }
    }
    if (lcm != A[N-1]) { std::cout << N << "\n"; return; }
    vi factors = factor_naive(A[N - 1]);
    int ans = 0;
    for (int f : factors) {
        int cur = 1, ct = 0;
        bool app = false;
        for (int a : A) {
            if (a == f) { app = true; break; }
            if (f % a == 0) {
                cur = std::lcm(cur, a);
                ct++;
            }
        }
        if (cur == f && !app) {
            // std::cout << f << "\n";
            ans = max(ans, ct);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}