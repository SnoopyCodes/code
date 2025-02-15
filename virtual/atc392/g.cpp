#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    const int MAXV = 1e6;
    vec<bool> appear(MAXV + 1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        appear[x] = true;
    }
    //that was dumb
    //ok so uh
    //wait start from the left say
    //move one over
    //uhh element <= 1e6 dont even sort it bruh
    //each element can only appear once
    //set element to pivot
    //maybe this is a counting problem
    //uhh
    //find equidistant numbers
    //if we move from left to right
    //we have one more number that might contribute, and we can check that
    //what about other numbers that were contributing?
    //left is dist further, right is dist closer
    //let original separation of left contributor be dl, right dr
    //dl + dist = dr - dist
    //1 2 3 5 8 9
    //1-2-3
    //1-3-5
    //2-5-8
    //1-5-9
    //1, 2, 4 are active, 3, 5, 6 are not
    //
}