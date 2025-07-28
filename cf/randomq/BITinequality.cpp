#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
#define int long
#define tp template
tp<int z> using ints = std::array<int, z>;
tp<int z> using longs = std::array<long, z>;

tp<class T> using vt = vector<T>;
tp<class T> using vv = vt<vt<T>>;

void solve() {
    int N; std::cin >> N;
    vt<int> A(N);
    vv<int> msb(32);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        for (int b = 31; b > -1; b--) {
            if (A[i] & 1 << b) {
                msb[b].push_back(i);
                break;
            }
        }
    }

    long ans = 0;

    for (int b = 0; b < 32; b++) {
        vt<int> pf(N), sf(N);
        vt<bool> pfst(N), sfst(N);
        bool cur = false;
        for (int i = 0; i < N; i++) {
            cur ^= bool(A[i] & 1 << b);
            pf[i] += cur;
            pfst[i] = cur;
            if (i < N - 1) { pf[i + 1] = pf[i]; }
        }
        cur = false;
        for (int i = N - 1; i > -1; i--) {
            cur ^= bool(A[i] & 1 << b);
            sf[i] += cur;
            sfst[i] = cur;
            if (i > 0) { sf[i - 1] = sf[i]; }
        }
        for (int i : msb[b]) {
            /*
            oh my god okay
            get right side
            the xor of the two ranges not including i should be odd parity
            we want empty range
            */
            int odd_more = pf[N - 1] - pf[i];
            int even_more = N - i - 1 - odd_more;
            if (pfst[i]) { std::swap(odd_more, even_more); }
            even_more++;
            int odd_less = sf[0] - sf[i];
            int even_less = i - odd_less;
            if (sfst[i]) { std::swap(odd_less, even_less); }
            even_less++;
            // std::cout << odd_more << " " << even_more << " " << odd_less << " " << even_less << "\n";
            ans += (long) odd_more * even_less + (long) even_more * odd_less;
        }
    }
    std::cout << ans << "\n";
    
}

signed main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}