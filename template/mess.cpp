#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define one 1LL

const int INF = 4e18;

template<size_t z> using ints = std::array<int, z>;
using vi = vector<int>;
template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector(f, mvec<T>(r...)); }
#define tpct template<class T>
tpct using vt = vector<T>;
tpct using vv = vt<vt<T>>;
tpct istream& operator>>(istream& os, vt<T> a){
    for (T &x : a) { cin >> x; }
    return os;
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N = 2;
    vv<int> grid(N, vt<int>(N)); cin >> grid;
}