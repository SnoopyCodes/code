#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    vector<array<int, 2>> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i][0]; cities[i][0]--;
        cities[i][1] = i;
    }
    sort(cities.begin(), cities.end());
    
    //let's do actual thinking lmfao
    //im guessing that every single one is like within a range
    //iterate in order of increasing a[i]; if at any point the range is > a[i] then welp its cooked
    //so at each time intersect the intervals 

    int l = 0, r = N;
    int lc = N, rc = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (cities[j][0] == i) {
            lc = min(cities[j][1], lc);
            rc = max(cities[j][1], rc);
            l = max(l, cities[j][1] - i);
            r = min(r, cities[j][1] + i);
            j++;
        }
        if (rc - lc > i) { cout << 0 << "\n"; return; }
    }
    cout << r - l + 1 << "\n";

}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}