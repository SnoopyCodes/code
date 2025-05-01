#include <bits/stdc++.h>

using namespace std;

//welcome to incredibly slow (but correct) mathematics

int fdiv(int n, int d) {
    int q = n / d, r = n % d;
    if (r != 0 && ((n < 0) != (d < 0))) { q--; }
    return q;
}

int cdiv(int n, int d) {
    int r = n % d;
    return fdiv(n, d) + (r != 0);
}

long fdiv(long n, long d) {
    long q = n / d, r = n % d;
    if (r != 0 && ((n < 0) != (d < 0))) { q--; }
    return q;
}

long cdiv(long n, long d) {
    long r = n % d;
    return fdiv(n, d) + (r != 0);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //essentially, c++ doesn't perform floor division- it performs truncation towards 0 division
    //therefore, -2/4 = 0
    cout << fdiv(-5, 4) << "\n";
}