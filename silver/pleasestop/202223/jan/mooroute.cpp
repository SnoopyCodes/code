#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> cross(N);
    int total = 0;
    for (int i = 0; i < N; i++) {
        cin >> cross[i];
        total += cross[i];
    }
    //strategy: right, left, right, left etc
    //if next right is 0
    string ans = "";
    int pos = 0;  //the next one we are to cross
    int dir = 1;
    while (total--) {
        if (cross[pos] == 0 || cross[pos] == 1 && cross[pos - dir] > 1 || 
        (pos == -1 || pos == N)) { dir = -dir; pos += dir; }
        cross[pos]--;
        pos += dir;
        ans += dir == 1 ? 'R' : 'L';
    }
    cout << ans << "\n";
}