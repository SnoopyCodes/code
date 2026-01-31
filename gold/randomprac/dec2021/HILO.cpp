#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<int> A(N);
    for (int &u : A) {
        cin >> u, u--;
    }

    /*
    urgggh retry this
    x -> x + 1 then
    simple update
    we start all as HI
    consider the behavior of a HI
    might be hidden by smaller indexes in front
    so it will become HI when there are no indexes in front of it smaller than it
    
    consider LO
    it always is apparent at first. it becomes hidden if there is an element in front larger than it

    consider a LO. we have a sequence of increasing LO, and decreasing HI. if we are HILO,
    we take the most recent HI, if not already taken.

    if we are not contributing as a LO, we will never contribute again.
    either we are overshadowed (permanent) or there is no hi between us and the previous lo

    if we are contributing as a HI, we will always contribute until we don't
    for a LO, i believe there is a unique HI.
    suppose as we spawn in LO, 2 cases:
    it doesn't contribute:
        it'll never contribute
        how can we detect this?
        if there is an element < us in between us and our HI. it will already be LO
    it contributes:
        there is a HI that contributes. can there be a LO that pops up between the two?
        if there is, it overshadows our LO. how can we find this LO?

    for any LO x, the HI y is the smallest y > x in indices < i
    what a problem
    */

    vt<int> pos(N);
    for (int i = 0; i < N; i++) pos[A[i]] = i;
    vt<int> diff(N);
    vt<bool> marked(N);
    vt<int> cl(N, N); //find smallest index larger than us with index less, or N
    for (int i = N - 1; i > -1; i--) {
        int j = i + 1;
        while (j != N && pos[i] < pos[j]) { j = cl[j]; }
        cl[i] = j;
    }
    for (int i = 0; i < N; i++) {
        int j = cl[i];
        if (j < N && !marked[j]) {
            marked[j] = true;
            diff[i]++;
            diff[j]--;
        }
    }
    int cur = 0;
    cout << cur << "\n";
    for (int i = 0; i < N; i++) {
        cur += diff[i];
        cout << cur << "\n";
    }


}