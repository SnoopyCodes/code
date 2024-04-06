#include <bits/stdc++.h>

using namespace std;
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int N = profits.size();
    //okay so we try and choose the highest profit that we can afford at all times
    //we can use like a map to store what we can't reach, and a priority queue for what we can
    //then pop from pq and add to pq for every single thing?
    map<int, vector<int>> not_reach;
    priority_queue<int> reach;
    for (int i = 0; i < N; i++) {
        if (capital[i] > w) { not_reach[capital[i]].push_back(profits[i]); }
        else { reach.push(profits[i]); }
    }
    while (k != 0 && !reach.empty()) {
        k--;
        w += reach.top();
        reach.pop();
        while (not_reach.begin() != not_reach.end() && (*not_reach.begin()).first <= w) {
            for (auto p : (*not_reach.begin()).second) {
                reach.push(p);
            }
            not_reach.erase(not_reach.begin());
        }
    }
    return w;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a{1, 2, 3}; vector<int> b{0, 1, 2};
    cout << findMaximizedCapital(3, 0, a, b) << "\n";
}