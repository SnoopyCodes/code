#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back

const int BIG = 1e9 + 1;
const long INF = 4e18 + 7e9;

template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;

template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;
//literally untypeable but best usability
//however we literally only ever need this for dp
//which is fulfilled by the lower construct
// template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
//     template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
// template<class T> struct mt<T, 1> : public vt<T> { using vt<T>::vt; };

// //typeable but only good for one case (which is good enough?)
// template<class... A> auto mv(int n, A&&... r) {
//     if constexpr(sizeof...(r) == 1) return vt(n, r...);
//     else return vt(n, mv(r...));
// }


int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int N = 5;
    vt<int> a(N);
    // mt<int, 2> G(N); //graph
    // mt<int, 2> M(N, N); //grid filled to NxN
    // vt<vt<int>> S(N, vt<int>(N));
    // vt<vt<int>> g(N);

    // auto gg = mv(N, vt<int>()); //useless for graphs.
}