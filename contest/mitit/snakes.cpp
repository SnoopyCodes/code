#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e3;

struct query
{
  int tlx, tly, brx, bry;
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    //all nodes have indegree 2
    //
}