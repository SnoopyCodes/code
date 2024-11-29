#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<array<int, 2>> interval(N);
    for (int i = 0; i < N; i++) {
        cin >> interval[i][0] >> interval[i][1];
    }
    vector<long long> diff(2 * M + 2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int s = interval[i][0] + interval[j][0];
            int e = interval[i][1] + interval[j][1];
            diff[s]++;
            diff[e+1]--;
        }
    }
    long long sum = 0;
    for (int i = 0; i <= 2 * M; i++) {
        sum += diff[i];
        cout << sum << "\n";
    }
}