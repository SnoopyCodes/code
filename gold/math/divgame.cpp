#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    long N; cin >> N;
    //z is differnt than all integers chosen in previous operations
    vector<int> res(44);
    res[1] = 1;
    for (int i = 2; i < 44; i++) {
        for (int j = 0; j < 9; j++) {
            if (i >= j * (j + 1) / 2) { res[i] = j; }
        }
    }
    int ans = 0;
    for (int i = 2; (long) i * i <= N; i++) {
        int cnt = 0;
        while (N % i == 0) { cnt++; N /= i; }
        ans += res[cnt];
    }
    if (N != 1) {
        ans++;
    }
    cout << ans << "\n";
}