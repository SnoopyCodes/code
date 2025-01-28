#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }
    int s = 0, e = 1e9;
    //find the maximum s such that we cut down at least M
    while (s + 1 < e) {
        int m = (s + e) / 2;
        long res = 0;
        for (int i = 0; i < N; i++) {
            res += max(0, height[i] - m);
        }
        if (res >= M) { s = m; }
        else { e = m; }
    }
    cout << s << endl;
}