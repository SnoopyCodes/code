#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1e9 + 7;
template<int z> using ii = array<int, z>;
template<class T> using vt = vector<T>;

// template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
//     template<class...A> mt(int n = 0, A... r) : vt(n, mt<T, D - 1>(r...)) {} };
// template<class T> struct mt<T, 1> : public vt<T> { using vt<T>::vt; };


template<class T, T d = T{}> struct V : public vector<T> {
    T &operator[](int i) {
        while (this->size() <= i) { this->push_back(d); }
        return this->at(i);
    }
}; //120: slower, no worry about going over, initialization

//87 chars...
//vt dp(N, vt(M, vt(K, 0LL))); does perfectly fine...
//auto dp = mv(N, M, K, 0LL); -> significantly clearer.
auto mv(auto a) { return a; }
auto mv(int n, auto... r) { return vector(n, mv(r...)); }

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    // int N = 5, M = 6, K = 3;
    // mt<int, 2> test(5, 3);
    // auto v = mv(2, 2, 3);
    // vt s(vt(2, 2LL));
    // vt<vt<int>> g(N);
    // auto g = mv(N, vt<int>());
    V<int> way;
    cout << "??" << endl;
    cout << way[0] << "\n";
    way[5] = 5;
    
}