#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, F; cin >> N >> F;
    vt<int> R(N);
    rep(i, 0, N) {
        cin >> R[i];
    }
}
/*
func graph immediately
some farmers will fill into the final cycle
which could k*ll bessie
okay
bessie can rest infinitely iff there's no farmers in her cc
or there's no farmers "behind" her
these cases are not too hard to figure out, but now we get into modulo math, and trees


is this painful? 
so we have a given # of rest steps and we have to find a time to get into the cycle
we have to see which cycle things are marked to be entered by farmers.

there is not really an easy way to do this?
if bessie waits, she should wait at the beginning?
not necessarily.
N^2 is doable on this for me

let's try this one
how do we do this one
a_i != i

the main difficulties i see are for a node, we have to consider the chasing farmer
the tree merging from other farmers
and the possible open nodes

oh shoot
for a node of depth d in its tree (before entering)
wait we can do chaining somehow
if the farmer is depth d + 1 then know how we are forced to move. if we make it we dont
comparing depths as well.

i see how to do it now
but like cycle decomp in 30 minutes is pretty brutal

*/