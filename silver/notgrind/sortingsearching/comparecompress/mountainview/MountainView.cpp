#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<bool, pair<int, int>> &p1, pair<bool, pair<int, int>> &p2) {
    if (p1.second.first - p1.second.second == p2.second.first - p2.second.second) { return p1.second.first > p2.second.first; }
    return p1.second.first - p1.second.second < p2.second.first - p2.second.second;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<bool , pair<int, int>>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].second.first >> v[i].second.second;
    }
    //to check if a mountain encompasses another:
    //abs(x2-x) > y2-y
    //ok so if we sort by shortest peak what
    sort(v.begin(), v.end(), cmp);
    //sort by "range" of a mountain and see what is encompassed by what
    int count = N;
    int i = 0;
    while (i < N) {
        if (v[i].first) { i++; continue; }
        int dummy = i+1;//could be all of them...
        while (dummy < N && v[dummy].second.first - v[dummy].second.second <= v[i].second.first + v[i].second.second) {
            if (!v[dummy].first && abs(v[i].second.first - v[dummy].second.first) <= v[i].second.second - v[dummy].second.second) {
                count--;
                v[dummy].first = true;
            }
            dummy++;
        }
        i++;
    }
    cout << count;
}