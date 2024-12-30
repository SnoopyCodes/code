#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N; cin >> N;
    vector<array<long, 2>> jobs(N);
    for (int i = 0; i < N; i++) {
        cin >> jobs[i][1] >> jobs[i][0];
    }
    sort(jobs.begin(), jobs.end());
    //hmm
    //possible not possible
    //it is possible that we will execute our sequence of operations not as sorted
    //is it possible the same for time taken?
    //yes, it is possible
    //thus, there is no way to guarantee that
    //therefore, i believe our goal is insertion of an element into the sequence
    //such that time end sum remains the same and all constraints are satisfied
    //i believe in LIS!
    //our sequence is essentially made up of sets of 3 things: time started, time to be taken, 
    //and time before unable to start (free time)
    //ideally we can add on to this in some way-- find the latest time we can be added in
    //recall the default strat for it: take the one that ends earliest
    //1 10
    //8 3, 7 4
    //well decide if it's useful or not!
    //we need a wy to make it easier
    //i don't believe this is lazy segtree
    //try defining a dp, N^2 to start is even good
    //put in 1, 0 because i want it as subsequence
    vector<array<long, 3>> list;
    for (int i = 0; i < N; i++) {
        //find a place to insert it, if we can
        //uhhhhhh i dont think this works
        //soooo what?
        //
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}