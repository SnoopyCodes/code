#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //5 choices
    //dp
    array<vector<long>, 5> ways;
    for (int i = 0; i < 5; i++) {
        ways[i].resize(N); ways[i][0] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            ways[j][i] = ways[j][i-1];
            for (int k = 0; k < j; k++) {
                ways[j][i] += ways[k][i-1];
            }
        }
    }
    long ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += ways[i][N - 1];
    }
    cout << ans << "\n";
}