#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> instruct(N+1);
    for (int k = 0; k < K; k++) {
        int s, e;
        cin >> s >> e;
        s--;
        instruct[s]++; instruct[e]--;
    }
    int sum = 0;
    for (int i = 1; i < N+1; i++) {
        instruct[i] += instruct[i-1];
    }

    sort(instruct.begin(), instruct.end());
    cout << instruct[N/2+1];
}