#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> circle(N);
    for (int i = 0; i < N; i++) {
        cin >> circle[i];
    }
    vector<int> rearrange;
    sort(circle.begin(), circle.end());
    for (int l = 0, r = N - 1; l <= r; l++, r--) {
        if (l != r) { rearrange.push_back(circle[l]); }
        rearrange.push_back(circle[r]);
    }
    long answer = 0;
    for (int i = 0; i < N; i++) {
        answer += abs(rearrange[(i+1) % N] - rearrange[i]);
    }
    cout << answer << "\n";
}