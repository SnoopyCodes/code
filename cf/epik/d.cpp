#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> v(N);
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        v[i] = x;
        m[v[i]]++;
    }
    //the process is this:
    //alice starts at smallest
    //bob eats the ones with least frequency and > alice
    //thats it just simulate
    //no bob does not eat the ones with least frequency bob needs to eat 
    //the ones that bob can eat before alice reachest it
    //help wtf happened
    //i think we should rewrite a dp for bob
    //yes we should dp for bob
    //how though
    //
    vector<array<int, 2>> freq;
    for (auto x : m) {
        freq.push_back({x.first, x.second});
    }
    N = freq.size();
    // for (int i = 0; i < N; i++) {
    //     cout << freq[i][0] << " " << freq[i][1] << "\n";
    // }
    // cout << "\n";
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    //this dp maintains what
    //because if we do this dp
    //base it off the one we're gonna eat
    //then we need the location of alice, and the number of things we've eaten
    //so we have at [i][j] the numbe rof things we've eaten before eating cake i
    //when alice is at j
    //lets move
    //base case?
    //0, 0
    int bst = 0;
    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;  //
    }
    for (int i = 0; i < N; i++) {  //to eat
        //for every position of alice before we eat this
        for (int j = 0; j < N; j++) {
            if (i > 0) {
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
        }
        for (int j = 0; j < i; j++) {  //j must be less than i
            //if it is possible to eat this one
            if (dp[i][j] == -1) { continue; }
            //then alice can have eaten up to j + dp[i][j]?
            if (dp[i][j] + j + freq[i][1] > i) {  //time it takes to eat
                continue;
            }
            //otherwise it is valid and we go to the next one
            if (j + freq[i][1] >= N) {
                dp[i+1][N] = max(dp[i+1][N], dp[i][j] + 1);
            }   else {
                dp[i+1][j + freq[i][1]] = max(dp[i+1][j + freq[i][1]], dp[i][j] + 1);
            }
            bst = max(bst, dp[i][j] + 1);
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << N - bst << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}