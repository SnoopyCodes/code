#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //i don't suppose we can binary search on it?
    //we can either add to block, start subarray, or add to previous subarray
    //so we need to know the current subarray sum (cost) and the blocked elements so far
    //  
    for (int i = 0; i < N; i++) {
        
    }
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}