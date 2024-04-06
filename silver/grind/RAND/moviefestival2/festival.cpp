#include <bits/stdc++.h>

using namespace std;
vector<array<int, 2>> movies;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    movies.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i][0] >> movies[i][1];
    }
    multiset<int> watching;  //the watching
    int total = 0;
    sort(movies.begin(), movies.end());
    for (int i = 0; i < n; i++) {
        while (!watching.empty() && *watching.begin() <= movies[i][0]) { watching.erase(watching.begin()); k++; }
        if (!k && *watching.rbegin() > movies[i][1]) {
            watching.erase(--watching.end());
            watching.insert(movies[i][1]);
        }   else if (k) {
            k--;
            total++;
            watching.insert(movies[i][1]);
        }
    }
    cout << total << "\n";
}