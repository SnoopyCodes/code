#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
    int N, B; cin >> N >> B;
    vector<array<int, 2>> tiles(N);
    for (int i = 0; i < N; i++) {
        cin >> tiles[i][0];
        tiles[i][1] = i;
    }
    vector<array<int, 2>> boots(B);
    for (int i = 0; i < B; i++) {
        cin >> boots[i][0] >> boots[i][1];
    }
    sort(tiles.begin(), tiles.end());
    //ok now as we work for depths 0 upwards, we need to find the longest diff in this
    //or we could work from the end
}