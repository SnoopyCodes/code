#include <bits/stdc++.h>

using namespace std;

template <typename T> using vec = vector<T>;

//usage: auto x = multivec<T>(len1, len2, len3, ..., default value)
//why did i make this? idk
//

template <typename T> T mvec(T def) { return def; }
template <typename T, typename... Ds>
auto mvec(size_t fd, Ds... rd) {
    return vector<decltype(mvec<T>(rd...))>(fd, mvec<T>(rd...));
}

void hm(auto x) {
    cout << "type safety is not a rela thing" << "\n";
    cout << x[0];
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    auto x = mvec<int>(N, 3);
    for (int i = 0; i < N; i++) {
        cout << x[i] << endl;
    }
    auto y = mvec<double> (N, 3.0);
    auto z = mvec<long long>(N, 4LL);  //need LL
    hm(x);
    int M = 4;
    auto twod = mvec<int>(N, M, -2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << twod[i][j] << " ";
        }
        cout << endl;
    }
}