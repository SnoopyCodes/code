#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, K; cin >> N >> K;
    vt<int> A(N), B(N);
    for (int &u : A) cin >> u;
    for (int &u : B) cin >> u;
    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
/*
so haybale -= 1, and feed += 1
N <= 5e4 -> sqrt(N)?
this is really not fun... more grouping
can we binary search?
it might be a convex function we can ternary search on.

i feel as though if we
fix min
binary search
return max - min value
ternary search
we can get a good answer

because this fits with constraints

there might be a greedy grouping though
but we should try this?
wait i feel ike this doenst work?

whats the brute force?
find max a, min b. if there is one with same index, decrease
otherwise, arbitrarily increase one.
we can choose to increase 

suppose we want to check if the length can possibly be x
then we know that min(b) must be a certain value, and only a range of values satisfies this.

for a certain min(b) y can we query the cost? the cost for each is 
max(0, a_i - (x + y), y - b_i)
and it is only valid if sum of all costs <= K
if we binary search on x
isn't that a convex function?
so we can ternary search on it.

okay so for this it might just be merge boundaries tbh
at least thats for sbtask 2

sort by A
we will eventually just merge the A values
oh you sort the A values and B values then for each A to merge together
you binary search on how far you can put Bs together?

feel like thats not it but
sort by A

*/