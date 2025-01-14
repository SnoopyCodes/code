#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key
#define at find_by_order

using namespace __gnu_pbds;

template <class T>
using imset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //? isn't this sweep over it with a gp hash map ?
    //otherwise its a pain to maintain the thing
    imset<int> is;
    int med = K * K - (K * K / 2 - 1);
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int vis = 1, dir = 0;  //head right
    int r = 0, c = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            is.insert(grid[i][j]);
        }
    }
    int ans = *is.at(med);
    while (vis < (N - K + 1) * (N - K + 1)) {
        vis++;
        if (dir == 0 && c + K == N || dir == 1 && c == K) {
            dir = !dir;
            //chop off top layer, move one down
            for (int i = 0; i < K; i++) {
                is.erase(is.upper_bound(grid[r][c + i]));
            }
            for (int i = 0; i < K; i++) {
                is.insert(grid[r + K][c + i]);
            }
            r++;
        }   else if (dir == 0) {  //move right
            for (int i = 0; i < K; i++){
                is.erase(is.upper_bound(grid[r + i][c]));
            }
            for (int i = 0; i < K; i++) {
                is.insert(grid[r + i][c + K]);
            }
            c++;
        }   else {  //move left
            c--;
            for (int i = 0; i < K; i++) {
                is.erase(is.upper_bound(grid[r + i][c + K]));
            }
            for (int i = 0; i < K; i++) {
                is.insert(grid[r + i][c]);
            }
        }
        ans = min(ans, *is.at(med));
        for (int x : is) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "\n";
    }
    cout << ans << "\n";

}