#include <bits/stdc++.h>

using namespace std;

#define add push_back
#define ld long double
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;



signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T, K; cin >> T >> K;
    vt<ld> choose(T + 1); //(T choose i) / 2^T
    for (int i = 0; i <= T; i++) {
        
    }
}

/*
pure math
they are not asking for modulus, very interesting

okay.
so for bessie, the optimal strategy is:
repeat flips arbitrary n times until we obtain x flips, where we 
are not expected to roll > x in K - n flips.
how do we find the maximum we are expected to flip in y turns?


we want a function f(K) where it tells us our answer for k guesses left
then, if we do y turns, we should only stop if f(K - y) > rolled #

bro i literally wrote it out and still fucked up

just go backwards
f(0) = 0

to find for f(x + 1) the rolled number must be greater than f(x)
like
its essentially the same thing

suppose that number we roll further is y
if we roll >= y then we win

we can thus calculate the chance we stop on this roll
otherwise we defer to f(x)


*/
