#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, a, b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;


template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> { using vt<T>::vt; };



// template<class... A> auto mv(int n, A&&... r) {
//     if constexpr(sizeof...(r) == 1) return vt(n, r...);
//     else return vt(n, mv(r...));
// }

// template<class T> T mvec(T v) { return v; }
// template<class T, class...D> auto mvec(int n, D...r) {
//     return vt (n, mvec<T>(r...));
// }

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    mt<int, 2> test(5, 3);
    
}