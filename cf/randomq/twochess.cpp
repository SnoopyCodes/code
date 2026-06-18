#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    /*
    this seems pretty dang hard...
    a_i, b_i
    upper bound on moves is 4N
    consider a tree dp?
    wait here is an idea of all time

    depth of a <= depth of b, when possible.
    ah eventually they have to return to root very good.
    if the targets are within d, then let loose.
    sigh. 3 dfs. i'm too lazy to do this.
    */
}