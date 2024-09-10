#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<array<int, 2>> movies(N);
    for (int i =0; i < N; i++) {
        cin >> movies[i][1] >> movies[i][0];
    }
    sort(movies.begin(), movies.end());
    int cnt = 0;
    int to = 0;
    for (int i = 0; i < N; i++) {
        //take the movie that ends soonest
        if (movies[i][1] < to) { continue; }
        cnt++;
        to = movies[i][0];
    }
    cout << cnt << "\n";
}