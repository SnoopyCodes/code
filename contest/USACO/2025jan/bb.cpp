#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> line(N);
    vector<vector<int>> in_line(N);
    for (int i = 0; i < N; i++) {
        cin >> line[i]; line[i]--;
        in_line[line[i]].push_back(i);
    }
    vector<int> check(N);
    vector<vector<int>> in_check(N);
    for (int i = 0; i < N; i++) {
        cin >> check[i]; check[i]--;
        in_check[check[i]].push_back(i);
    }
    long ans = 0;
    for (int i = 0; i < N; i++) {
        if (check[i] == line[i]) {
            ans += (i * (i - 1)) / 2 + ((N - i - 1) * (N - i - 2)) / 2;
            ans += i + N - i - 1;
        }
    }
    //now for the real part
    for (int i = 0; i < N; i++) {
        vector<int> cows = in_line[i];
        vector<int> doc = in_check[i];
        for (int c : cows) {
            for (int d : doc) {
                if (c > d) { swap(c, d); }
                ans += min(c + 1, N - d);
            }
        }
    }
    cout << ans << "\n";
}