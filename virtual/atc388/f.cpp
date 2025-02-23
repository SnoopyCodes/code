#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const long INF = 4e18 + 7e9;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    long N; cin >> N;
    //well shoot
    int M, A, B; cin >> M >> A >> B;
    long l = 1, r = 1;  //possible range of where we can be?
    rep(i, M) {
        long ql, qr; cin >> ql >> qr;
        //shoot im dumb
        //i feel as if, though, that the bound can be reduced ish
        //because it takes at most 400 steps for it to be able to reach any- is this true?
        //
        //unless it is only range one, in which case solution is simple
        //otherwise we can calculate the reachability
        //we can actually precalculate the reachability of a range given a range
        //this takes at most like not a lot of time to set up
        //and we do this for the up to 20 squares before each range
        //so... im guessing potato was not locked in
        //took everyone 20 minutes though so maybe he did cook
    }

}