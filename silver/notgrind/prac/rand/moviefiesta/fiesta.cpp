#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<pair<int, int>> movies;
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) { return p1.first > p2.first; }
    return p1.second < p2.second;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    movies.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    //okay so there are just k movies that we can watch at once
    //is it possible to sort and pair stuff so that we can find 
    //is it ALWAYS optimal to select the movies ending soonest
    //i guess
    //use a map for starting and end? probably
    sort(movies.begin(), movies.end(), comp);
    priority_queue<int> pq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && -pq.top() <= movies[i].first) {
            pq.pop();
        }
        if (pq.size() != k) {
            ans++;
            pq.push(-movies[i].second);
        }
    }
    cout << ans << "\n";
}