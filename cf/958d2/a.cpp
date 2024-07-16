#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    //break into blocks of size k
    //right
    //if its greater than k^2 then we need to break into 
    //k * k
    //break it into powers of k
    //right
    //we can always do N operations
    //do N/K
    //break it into as many K * K or whatever
    //then math that 
    int bet = K * K;
    while (K * bet <= N) {
        bet *= K;
    }
    
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}