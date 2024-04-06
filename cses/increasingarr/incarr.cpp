#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long need = 0;
    for (int i = 1; i < N; i++) {
        need += arr[i] < arr[i-1] ? arr[i-1] - arr[i] : 0;
        if (arr[i] < arr[i-1]) { arr[i] = arr[i-1]; }
    }
    cout << need << "\n";
}