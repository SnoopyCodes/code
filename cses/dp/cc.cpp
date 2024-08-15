#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
vector<int> skills;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //coidng company
    int N, X; cin >> N >> X;
    skills.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> skills[i];
    }
    sort(skills.begin(), skills.end());
    //we can calculate
    //if we choose a range we take every single one
    //define dp[i][cost] to be the number of ways modulo mod to 
    //divide coders 0...i inclusive into teams
    //how tf
    //uhh
    //wait we only need to query for the smallest in a range
    //no
    //run knapsack on knapsacks
    //uhhh
    //we should not be sorting lmfao it dont matter
    //dp[i][start][end]...
    //ah. the path forward clears.
    //d[i][start][cost].
    vector<vector<vector<int>>> ways(N + 1, vector<vector<int>>(N, vector<int>(X+1)));
    ways[0][0][0] = 1;
    for (int i = 1; i < N; i++) {
        //add skills[i] - skills[j]
        //5e7 works right
        
        //given a certain 0 <= j <= i, we want to add each of its starts and costs
        //
    }
    int ans = 0;
    for (int i = 0; i < X + 1; i++) {
        
        ans %= MOD;
    }
    cout << ans << "\n";
}