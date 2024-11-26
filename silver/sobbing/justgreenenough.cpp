#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> pasture;

//O(N^3) time pls
//i hate grid problems
//devise some method to find minimum of subgrids help
//use left and right pointers over columns
//simplify it into 0's and 1's
//any valid grid needs to have all 1's
//this is very doable in O(N^4) time now- first subtask
//using prefix sums
//now we can very likely use pruning of some sort
ll submin(int ming) {
    int N = pasture.size();
    vector<vector<int>> valid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            valid[i][j] = pasture[i][j] >= ming;
        }
    }
    ll res = 0;
    //set a left, right pointer
    //what's the speedup?
    //set a left pointer to sweep over the grid
    for (int i = 0; i < N; i++) {  //left pointer
        vector<int> sf(N);  //suffix minima xd
        for (int j = 0; j < N; j++) {  //height
            sf[j] = i;
            while (sf[j] < N && valid[sf[j]][j]) { sf[j]++; }
            for (int k = 0; k < j; k++) { sf[k] = min(sf[k], sf[j]); }
            //calculate
            for (int k = 0; k <= j; k++) {
                int width = sf[k] - i;
                //we have a fixed width and height now
                res += width;
            }
        }
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //help
    pasture.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pasture[i][j];
        }
    }
    //oh wait it needs to be N^3
    //we could probably 2d segtree cheese this
    //but "exactly" means that we can find all green >= 100, and subtract all green >= 101
    //very sad knowing this
    //anyways so how do we find with exactly some minimum?
    //if we set up a bound
    cout << submin(100) - submin(101) << "\n";
}