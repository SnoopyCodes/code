#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    int ops = 0;
    int threes = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x < 3) { ops += x; }
        else { threes++; }
    }
    //we can ONLY take gcd(x,y) = 1
    //if its just one, depends on parity
    //2 means nothing
    //alice wins 3 4 5
    //is it just 1, 2?
    //nah these tc are useless
    //1 2
    //A

    //1 3
    //A

    //2 3
    //B
    //3 3
    //i think it's 1, 2, > 3?
    //> 3 means control
    //i'll let them "claim" controls
    //and one balances another?
    //if control & 1 alice wins. ...false
    if (threes & 1) { cout << "Alice" << "\n"; return; }
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}