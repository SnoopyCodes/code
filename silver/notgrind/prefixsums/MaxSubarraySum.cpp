#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    long min = 0;
    long m = INT_MIN;
    for (int i = 1; i <= N; i++) {
        if (v[i] - min > m && v[i] != min) { m = v[i] - min; }
        if (min > v[i]) { min = v[i]; }
    }
    cout << m;
}