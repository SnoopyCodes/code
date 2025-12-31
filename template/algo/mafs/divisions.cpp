#include <bits/stdc++.h>

using namespace std;

//welcome to incredibly slow (but correct) mathematics

int fdiv(int a, int b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

int cdiv(int a, int b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

long fdiv(long n, long d) {
    long q = n / d, r = n % d;
    if (r != 0 && ((n < 0) ^ (d < 0))) { q--; }
    return q;
}

long cdiv(long n, long d) {
    return fdiv(n, d) + (n % d != 0);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //essentially, c++ doesn't perform floor division- it performs truncation towards 0 division
    //therefore, -2/4 = 0
    cout << fdiv(-5, 4) << "\n";
}