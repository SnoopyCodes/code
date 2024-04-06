#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> chicken;
vector<pair<int, int>> cow;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    //is it like have a priority queue of which cows are currently available, and then whichever one ends first you need to go ahead and move out
    //i think so
    int C, N;
    cin >> C >> N;
    chicken.resize(C);
    cow.resize(N);
    for (int i = 0; i < C; i++) {
        cin >> chicken[i];
    }
    sort(chicken.begin(), chicken.end());
    for (int i = 0; i < N; i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    sort(cow.begin(), cow.end());
    priority_queue<int> pq;
    int c = 0;
    int ans = 0;
    for (int i = 0; i < C; i++) {
        while (c < N && cow[c].first <= chicken[i]) { pq.push(-cow[c].second); c++; }
        while (!pq.empty() && -pq.top() < chicken[i]) { pq.pop(); }
        if (!pq.empty()) { pq.pop(); ans++; }
    }
    cout << ans << "\n";
}