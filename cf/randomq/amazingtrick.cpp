#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    vt<int> ia(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        ia[x-1] = i;
    }
    vt<bool> used(N);
    set<int> can;
    vt<int> first(N), iF(N);
    for (int i = 0; i < N; i++) { can.insert(i); }
    for (int i = 0; i < N; i++) {
        can.erase(i);
        can.erase(ia[i]);
        cout << i << ": " << endl;
        if (can.empty()) {
            cout << "Impossible" << "\n";
            return;
        }
        for (int x : can) cout << x << " ";
        cout << endl;

        first[i] = *can.begin();

        cout << first[i] << endl;
        iF[first[i]] = i;
        used[first[i]] = true;
        can.erase(can.begin());
        if (!used[i]) { can.insert(i); }
        if (!used[ia[i]]) { can.insert(ia[i]); }
        
        for (int x : can) cout << x << " ";
        cout << endl;
    }
    vt<int> second(N);
    for (int i = 0; i < N; i++) {
        //map first_i to ia_i
        second[i] = iF[ia[i]];
    }
    cout << "Possible" << "\n";
    for (int i = 0; i < N; i++) cout << second[i]+1 << " \n"[i == N - 1];
    for (int i = 0; i < N; i++) cout << first[i]+1 << " \n"[i == N - 1];
    

    
}
/*
the permutations have no fixed points..
we can invert the permutation a to figure out what we need to swap stuff to.
consider the identity permutation. we can create any derangement, and then invert it.
uhh
consider the fixed points of a_i. we have to move them, then move them back. 
just invert A, anyways.
we start from identity, then go to A.

basically, we just construct any permutation that has for all i inva_i != p_i and p_i != i
then find the permutation q that maps p to inva

consider 1 3 2
the inverse is 1 3 2?
3 1 2 should work
now map 3 1 2 to 1 3 2
2 1 3

now: can i get mathematical proof that we can construct for any N > 2?
try to induct on N = 3

choose a permutation. insert 4. swap 4 with any position, including itself. 
this is how we generate more permutations.
now how does this affect p and q?
suppose our method does not cause a fixed point at 4. 
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}