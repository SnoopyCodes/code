#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
void solve() {
    int N; cin >> N;
    //the state is 0, 0, we need to get to N, N
    //wait what states do we even iterate through
    //is there not a math solution?
    //(N - 1) * 2 + N bounds
    //and we want see which ones we can remoev
    //except we can't remove those that make irregulars
    //so if we remove any "wall"
    //we need to run in N things but how help
    //i think we need to do 
    vector<vector<ll>> pos(N, vector<ll>(N));
    for (int i = 0; i <= N; i++) {
        
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}   