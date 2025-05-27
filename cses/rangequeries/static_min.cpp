#include <bits/stdc++.h>


using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
const int MOD = 1e9 + 7;

#define rep(i,s,e) for(auto i=(s);i<(e);i++)
#define rev(i,s,e) for(auto i=(s) - 1;i>=(e);i--)

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

void dnc(int l, int r, int level, vector<int> &A, auto &range) {
    if (l + 1 == r) { range[level][l] = A[l]; return; }
    int m = (l + r) / 2;
    //find the answer to all that cross m
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    int NLG = std::__lg(N - 1) + 1;
    vector<int> A;
    auto range = mvec<int>(NLG, N, MOD);
    dnc(0, N, 0, A, range);
}