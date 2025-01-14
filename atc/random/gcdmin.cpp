#include <bits/stdc++.h>
#define vec vector
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<int> A(N);
    int minv = 1e9;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        minv = min(minv, A[i]);
    }
    set<int> s;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int cd = __gcd(A[i], A[j]);
            if (cd < minv) { s.insert(cd); }
        }
    }
    cout << (s.size() + 1) << "\n";
    //try to prove that pairwise gcds are the only existing:
    //gcd(A[i], A[j]) = x
    //ax = A[i], bx = A[j]
    //contradiction: gcd(A[k], x) <= gcd(A[i] or A[j], A[k])
    //gcd(A[k], x) <= gcd(ax, A[k])
    //which is obviously true.. praying
    //ok so it's not, unfortunately
    //
}