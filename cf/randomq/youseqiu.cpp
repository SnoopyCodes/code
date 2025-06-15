#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;;
#define long long long
template<int MOD> struct mint {
	int v;
	mint():v(0) {}
	mint(long _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, mint b) { return a.v + b.v; }
	friend mint operator*(mint a, mint b) { return (long)a.v*b.v; }
};
using mi = mint<998244353>;

template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N; std::cin >> N;
    //数色
    vector<int> shuse(N);
    for (int i = 0; i < N; i++) {
        std::cin >> shuse[i];
    }
    sort(shuse.begin(), shuse.end());
    //可能
    vector<mi> keneng(5001);
    mi ans = 0;
    keneng[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 5000 - shuse[i]; j >= 0; j--) {
            ans = ans + keneng[j] * max((shuse[i] + j + 1) / 2, shuse[i]);
            keneng[j + shuse[i]] = keneng[j + shuse[i]] + keneng[j];
        }
    }
    std::cout << ans.v << "\n";
}