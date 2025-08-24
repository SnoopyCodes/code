#include <bits/stdc++.h>

using namespace std;

#define long long long

const int BIG = 1e9 + 1;
const long INF = 4e18 + 7e9;

template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;
template<class T> istream& operator>>(istream& in, vt<T> &a){
    for (T &x : a) { in >> x; }
    return in;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    vt<int> a(3);
    vv<int> b(2, vt<int>(2));
    cin >> a;
    cin >> b;
}