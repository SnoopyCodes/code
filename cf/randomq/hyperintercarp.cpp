#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

/*
lets see
if we take t turns, we want to get as close as possible.

max is 20000? fair
we can bound it ourselves.

can always form exactly x or y.
suppose we make t turns.
turn 1 contributes t in that delta.
so we have the deltas 1...t and assign them to x or y to get as close to X or Y as possible.

uhhh... we only need to consider 2 t at maximum? yeah.
we want to minimize 2 t

...

*/

void solve() {
    int X, Y; cin >> X >> Y;
    int tot = 0;
    int t = 1;
    while (t + tot <= X + Y) {
        tot += t++;
    }
    t--;
    int T = t;
    int x = 0, y = 0;
    long long best = LONG_LONG_MAX;
    //by knapsack we can always pin down any value of x we want. so find the value
    //that minimizes max(X - x, Y - y) i.e. diff is as small as possible.
    int diff = X + Y - tot;
    bool swp = X < Y;
    if (swp) { swap(X, Y); }
    //... so X >= Y. 
    x = X - (diff + 1) / 2; //ceil if i know how to do math
    y = Y - diff / 2;
    //form x
    vt<bool> is_y(T, 1);

    tot = 0;
    for (t = T; t >= 1; t--) {
        //remember to invert
        if (tot + t <= x) {
            is_y[T - t] = false;
            tot += t;
        }
    }

    if (swp) {
        for (int i = 0; i < size(is_y); i++) {
            is_y[i] = !is_y[i];
        }
    }

    for (bool x : is_y) {
        cout << (x ? "Y" : "X");
    }
    cout << "\n";
    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}