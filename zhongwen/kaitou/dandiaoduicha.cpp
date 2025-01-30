#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && A[dq.back()] >= A[i]) { dq.pop_back(); }
        dq.push_back(i);
        if (i - dq.front() == K) { dq.pop_front(); }
        if (i >= K - 1) {
            cout << A[dq.front()] << " \n"[i == N - 1];
        }
    }
    dq.clear();
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && A[dq.back()] <= A[i]) { dq.pop_back(); }
        dq.push_back(i);
        if (i - dq.front() == K) { dq.pop_front(); }
        if (i >= K - 1) {
            cout << A[dq.front()] << " \n"[i == N - 1];
        }
    }
}