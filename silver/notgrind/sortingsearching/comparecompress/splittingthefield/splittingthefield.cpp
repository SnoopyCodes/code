#include <bits/stdc++.h>
//required multisets or smth idk
using namespace std;
struct Cow {
    int x, y;
    int xp, yp;
};
bool cx(const Cow &c1, const Cow &c2) {
    return c1.x < c2.x;
}
bool cy(const Cow &c1, const Cow &c2) {
    return c1.y < c2.y;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("split.in", "r", stdin);
    //freopen("split.out", "w", stdout);
    int N; cin  >> N;
    
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    vector<int> ycoords(N);
    vector<int> xcoords(N);
    sort(cows.begin(), cows.end(), cx);
    for (int i = 0; i < N; i++) {
        cout << cows[i].x << " ";
        xcoords[i] = cows[i].x;
        cows[i].xp = i;
    }
    cout << "\n";
    sort(cows.begin(), cows.end(), cy);
    for (int i = 0; i < N; i++) {
        cout << cows[i].y << " ";
        ycoords[i] = cows[i].y;
        cows[i].yp = i;
    }
    long long minarea = LONG_LONG_MAX;
    for (int i = 0; i < N - 1; i++) {
        int xl = xcoords[cows[i].xp] - xcoords[0];
        int yl = ycoords[cows[i].yp] - ycoords[0];
        int xh = xcoords[N-1] - xcoords[cows[i+1].xp];
        int yh = ycoords[N-1] - ycoords[cows[i+1].yp];
        long long area = xl * yl + xh * yh;
        minarea = min(area, minarea);
    }
    cout << "\n";
    cout << minarea;
    //for a point x, y
    //the area that is bounded is from lx to x * from ly to y plus hx - lx * hy - ly of the next points...
    //prefix sums, somehow
    //if we have 2 prefix sum arrays and we can point from one to another then
    //okso the idea is: for a point x, y we use 2 sorted vectors of x, ys and then figure out for each point what the area must be
}