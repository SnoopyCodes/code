#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> subarrays;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    subarrays.resize(N - 1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        for (int j = i + 1; j < N; j++) {
            cin >> x;
            subarrays[i].push_back(x);
        }
    }
    vector<int> arr(N);
    for (int i = 1; i < N; i++) {
        //check for each subarray 0... i
        //see how much allowance they give, basically
        arr[i] = arr[i-1] + subarrays[i-1][0];
        bool valid = true;
        for (int j = 0; j < i - 1; j++) {
            int s = INT_MAX, b = INT_MIN;
            for (int k = j; k <= i; k++) {
                s = min(s, arr[k]);
                b = max(b, arr[k]);
            }
            if (b - s != subarrays[j][i - j - 1]) { valid = false; break; }
        }
        if (!valid) {
            arr[i] = arr[i-1] - subarrays[i-1][0];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N - 1) { cout << " "; }
    }
    cout << "\n";

}