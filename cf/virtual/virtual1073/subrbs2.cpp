#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 998244353;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    /*
    what a cook
    range dp??
    but we have to solve for subsequences somehow
    mostly a matter of defining our dp thing
    what do we do with these bracket sequences?
    okay so we must have t as rbs
    then solve for t..
    dp_ijk?
    1, -1...
    there are a few things in a sequence: start, end, split point
    remember greedy works
    split point is particularly important
    split point, replacement point, start, end
    what relation do they have to each other?
    for # of starts between start and split point, there are at least that many closing in [rep, end]
    the answer is 2 * # of closing
    rep = first ( after split point

    legit though how do i count over all subsequences?
    uhhhh good question
    how do we quantify them? iterate over i as ending point? to start with?
    then iterate over replacement point? where is our dp? where is our recurrence?
    how do we satisfy the "better" condition?
    either suffixe thign is equal or 
    surely we can dp for # of subsequences with [x] balance from the suffix right?
    then what?
    we just find beginnings and do stuff with them?
    dpbal_ij = # of subsequences with i and j more ) than (?
    easy enough to dp probably
    then calculate dp for start i, j -> prefix balance, k -> split point?
    for the ) in between we multiply by 2^#
    then just suffix sum it?
    how did antares do this so freaking fast?
    */

    




}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}