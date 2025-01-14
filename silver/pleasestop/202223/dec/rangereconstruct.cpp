#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> range(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            cin >> range[i][j];
        }
    }
    //ok, how do we conduct this
    //set the last value to be 0
    //then find a value for the next one that satisfies the others
    //and so on
    vector<int> arr(N);
    auto valid = [&](int i) {
        for (int j = i; j < N; j++) {
            for (int k = 0; k + j < N; k++) {  //constraint range[j][k]
                int maxv = -1e9, minv = 1e9;
                for (int l = j; l <= k + j; l++) {
                    maxv = max(maxv, arr[l]);
                    minv = min(minv, arr[l]);
                }
                if (maxv - minv != range[j][k]) { return false; }
            }
        }
        return true;
    };
    for (int i = N - 2; i > -1; i--) {
        //wait okay one of the two values will satisfy the whole thing i think
        //what if one of them doesn't?
        //
        int diff = range[i][1];
        arr[i] = arr[i + 1] - diff;
        if (!valid(i)) { arr[i] = arr[i + 1] + diff; }
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " \n"[i == N - 1];
    }
}