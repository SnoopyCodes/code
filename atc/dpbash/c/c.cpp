#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<array<int, 3>> activities(N);
    for (int i = 0; i < N; i++) {
        cin >> activities[i][0] >> activities[i][1] >> activities[i][2];
    }
    vector<array<int, 3>> happy(N + 1);
    //store the happiness on day i where we have accomplished this activity
    for (int i = 0; i < N; i++) {
        int a = happy[i][0], b = happy[i][1], c = happy[i][2];
        happy[i+1][0] = activities[i][0] + max(b, c);
        happy[i+1][1] = activities[i][1] + max(a, c);
        happy[i+1][2] = activities[i][2] + max(a, b);
    }
    cout << max(happy[N][0], max(happy[N][1], happy[N][2]));
}