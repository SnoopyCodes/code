#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> dir;
int x, y;
bool works(long long days) {
    long long dx = x, dy = y;
    dx -= (days / dir.size()) * dir[dir.size()-1].first;
    dy -= (days / dir.size()) * dir[dir.size()-1].second;
    long long remainder = days % dir.size();
    if (remainder != 0) {
        dx -= dir[remainder-1].first;
        dy -= dir[remainder-1].second;
    }
    return days >= abs(dx) + abs(dy);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int sx, sy, ex, ey, n;
    string weather;
    cin >> sx >> sy >> ex >> ey >> n >> weather;
    x = ex - sx, y = ey - sy;
    dir.resize(n);
    for (int i = 0; i < weather.size(); i++) {
        if (weather[i] == 'U') { dir[i].second++; }
        else if (weather[i] == 'D') { dir[i].second--; }
        else if (weather[i] == 'R') { dir[i].first++; }
        else if (weather[i] == 'L') { dir[i].first--; }
        if (i != 0) {
            dir[i].first += dir[i-1].first;
            dir[i].second += dir[i-1].second;
        }
    }
    //now number of iterations necessary to bring it within 1 iteration of the destination
    //in addition to the wind we have n directions to help travel
    //how do we optimize the travel of the boat?
    //ok what if. we just binary search for a day that helps us find the ship?
    //then we have day / n iterations and can figure out the x and y quickly.
    //but then we need minimal # of days
    //so then we just decrease the upper bound
    //ok what if its impossible?
    //just keep increasing
    long long l = 0, r = LONG_LONG_MAX / 2;  //YES
    int count = 0;
    while (r - 1 >= l) {
        count++; if (count == 100000) { break; }
        long long m = l+(r-l)/2;
        if (works(m)) { r = m; }
        else { l = m; }
    }
    if (works(r)) cout << r;
    else cout << -1;
}