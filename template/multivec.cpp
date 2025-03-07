#include <bits/stdc++.h>

using namespace std;

template <typename T> using vec = vector<T>;

template <typename T>
T multivec(T def) { return def; }

template <typename T, typename... Dims>
auto multivec(size_t first_dim, Dims... rest_dims) {
    return vec<decltype(multivec<T>(rest_dims...))>(
        first_dim, multivec<T>(rest_dims...));
}

//usage: auto x = multivec<T>(len1, len2, len3, ..., default value)

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    auto x = multivec<int>(N, 3);
    for (int i = 0; i < N; i++) {
        cout << x[i] << endl;
    }
    int M = 4;
    auto twod = multivec<int>(N, M, -2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << twod[i][j] << " ";
        }
        cout << endl;
    }
}