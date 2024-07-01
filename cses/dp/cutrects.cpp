#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    //how cut? we can cut each rectangle into 2 rectangles
    //we need to figure out the optimal rectangle cuts by finding the minimum sum of both i think
    //the dp needs to be how many operations it takes to cut rectangle of size a, b up
    //wait 500^4 is 10^8 * 625
    //eh lets try it
    //wait we can't even N^2 thats not how rectangle sides work lol
    vector<vector<int>> cuts(N+1, vector<int>(M+1, 1000));
    for (int i = 0; i <= min(N, M); i++) {
        cuts[i][i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            //add to ones with the same height and width
            for (int k = 1; k <= i && i + k <= N; k++) {
                cuts[i+k][j] = min(cuts[i+k][j], cuts[i][j] + cuts[k][j] + 1);
            }
            for (int k = 1; k <= j && j + k <= M; k++) {
                cuts[i][j+k] = min(cuts[i][j+k], cuts[i][j] + cuts[i][k] + 1);
            }
        }
    }
    cout << cuts[N][M];
}