#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++) // i think ive decided i like this after looking at permutation again
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T, N, K; cin >> T >> N >> K;
    vt<int> w(N), x(N);
    rep(i, 0, N) {
        cin >> x[i] >> w[i];
    }
    if (T == 1) {
        //i dont even know?
        //there can definitely be a lot of maximal pairings
        //think local. try pair i with i + 1, if we can.
        //then move to i + 1. if we can pair, unpair if w[i] < w[i + 2]
        //if not paired, repeat with i := i + 2
        //if paired, move to i + 2
        //if can pair, pair?
        //this subtask doesn't seem too hard.
        //in a "connected component"
        //if even, all paired
        //if odd, choose 1 of the "odd indexed (1st, 3rd, 5th...)" to unpair
        //oh only if it needs to be unpaired :sob:
        //alr i get it usaco im not doing it
    }   else {
        //now how do we do this?
        //N <= 5000, max <= 1e4, that looks like dp
        //solve per connected component
        //obviously we have to iterate over i and see pairing/unpaired
        //how do we do this?
        //we have to see for i whether we want to leave it paired/unpaired.
        //we have to do like
        //0 or 1 unpaired that can be seen at this point.
        //the rule is if there's an element we see that is unpaired, we have to pair with it?
        //each element has 3 states: unpaired, pair left, pair right.
        //we can obviously condense pair left pair right
        //and thus the problem is solved?
        
    }
}