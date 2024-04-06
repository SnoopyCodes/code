#include <bits/stdc++.h>

using namespace std;
int GCD(int a, int b) { return gcd(a, b); }
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> prefix(N);  //v[i] = GCD of indexes before and up to
    vector<int> suffix(N);  //v[i] = GCD of indexes after and up to
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    prefix[0] = v[0];
    suffix[N-1] = v[N-1];
    for (int i = 1; i < N; i++) {
        prefix[i-1] = GCD(v[i-1], prefix[i-1]);
    }
    for (int i = N - 2; i >= 0; i--) {
        suffix[i] = GCD(v[i+1], suffix[i+1]);
    }
    int m = 0;
    for (int i = 0; i < N; i++) {
        if (m == 0) { m = suffix[0]; }
        else if (m == N - 1) { m = max(m, prefix[N-1]); }
        else {
            m = max(m, GCD(prefix[i-1], suffix[i+1]));
        }
    }
    cout << m;
}