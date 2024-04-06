#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> friends;
bool left_max;
bool right_max;
double time(double loc) {
    double mtime = 0;
    for (int i = 0; i < friends.size(); i++) {
        double t = abs(loc - friends[i].first) / friends[i].second;
        if (mtime < t) {
            left_max = false; right_max = false;
            if (friends[i].first > loc) { right_max = true; }
            else { left_max = true; }
            mtime = t;
        }   else if (t == mtime) {
            if (friends[i].first > loc) { right_max = true; }
            else { left_max = true; }
        }
    }
    return mtime;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    friends.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> friends[i].second;
    }
    sort(friends.begin(), friends.end());  //sorted by pos
    double s = friends[0].first, e = friends[n-1].first, mtime = INT_MAX;
    int count = 0;
    while (s < e-(10e-7)) {
        count++;
        if (count > 100) { break; }
        double m = (s+e)/2;
        mtime = min(mtime, time(m));
        if (left_max && right_max) { break; }
        else if (left_max) { e = m; }
        else { s = m; }
    }
    cout << mtime;
}