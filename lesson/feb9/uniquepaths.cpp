#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 8; //i cannot use my templates... bing chilling

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //oh no its my math templates
    //dude wait why mod 1e9 + 8
    //anyways C(i, j) = C(i-1, j-1) + C(i-1, j)?
    int N, M; cin >> N >> M; N--; M--;
    int K = N + M;
    //calculate K choose N
    vector<vector<int>> count(K+1, vector<int> (K+1));
    count[0][0] = 1;
    for (int i = 1; i <= K; i++) {
        count[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            count[i][j] = (count[i-1][j-1] + count[i-1][j]) % MOD;
        }
    }
    cout << count[K][N] << "\n";
}