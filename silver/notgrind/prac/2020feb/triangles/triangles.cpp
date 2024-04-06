#include <bits/stdc++.h>

using namespace std;
struct Point { int x, y; };
bool xsort(Point p1, Point p2) {
    return p1.x < p2.x;
}
bool ysort(Point p1, Point p2) {
    return p1.y < p2.y;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N; cin >> N;
    vector<Point> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }
    map<int, vector<int>> xmap;
    map<int, vector<int>> ymap;
    for (int i = 0; i < N; i++) {
        xmap[v[i].x].push_back(v[i].y);
    }
    for (int i = 0; i < N; i++) {
        ymap[v[i].y].push_back(v[i].x);
    }
    long long total = 0;
    long long lim = pow(10, 9) + 7;
    for (auto i : xmap) {//so i.first is the x-value we are on, and i.second has the y-values of the different points on the x-value.
        if (i.second.size() == 1) { continue; }
        for (int j = 0; j < i.second.size(); j++) {  //so the point we are looking at is i.first, i.second[j].
            if (ymap[i.second[j]].size() > 1) {  //if the vector at i.second[j] has size greater than 1
                int sumx = 0;  //sum the distances for values along x
                int sumy = 0;  //sum distances along y
                for (int y : i.second) {
                    sumy += abs(y - i.second[j]);
                }
                for (int x : ymap[i.second[j]]) {
                    sumx += abs(x-i.first);
                }
                total += (long long) sumx * sumy;
            }
        }
        if (total > lim) { total %= lim; }
    }
    cout << total;
    //there must be a way to find pivot points such that there are points at parallel lines from it with respect to x and y-axis.
    //coordinate compress. then figure out on which x values are there a line of the 
    //or no need to coord compress
    //use a map<int, vector<int>> to say that at x, there are these y values to choose from.
}