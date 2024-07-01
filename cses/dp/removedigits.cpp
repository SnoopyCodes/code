#include <bits/stdc++.h>

using namespace std;
vector<int> steps;
int run(int x) {
    if (x < 0) { return INT_MAX; }
    if (steps[x] != -1) { return steps[x]; }
    int tmp = x;
    int mn = INT_MAX;
    while (tmp > 0) {
        int dig = tmp % 10;
        if (dig != 0) {
            mn = min(mn, run(x - dig) + 1);
        }
        tmp /= 10;
    }
    steps[x] = mn;
    return mn;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    steps.resize(N+1, -1);
    steps[0] = 0;
    cout << run(N);
}