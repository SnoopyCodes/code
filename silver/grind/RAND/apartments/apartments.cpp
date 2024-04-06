#include <bits/stdc++.h>

using namespace std;
vector<int> want;
vector<int> sizes;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    want.resize(N);
    sizes.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> want[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> sizes[i];
    }
    sort(want.begin(), want.end());
    sort(sizes.begin(), sizes.end());
    int app = 0;
    int total = 0;
    priority_queue<int> apps;
    for (int home = 0; home < M; home++) {
        while (!apps.empty() && -apps.top() + K < sizes[home]) { apps.pop(); }
        while (app < N && want[app] - K <= sizes[home]) {
            if (abs(sizes[home] - want[app]) <= K) {
                apps.push(-want[app]);
            }
            app++;
        }
        if (!apps.empty()) { apps.pop(); total++; }
    }
    cout << total << "\n";
}