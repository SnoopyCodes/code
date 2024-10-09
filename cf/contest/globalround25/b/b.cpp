#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    K--;
    //check if anythings behind us
    //if things are behind us
    //how to determine number of wins?
    //wait hold on
    //did we check the thing with like where does swapping K get us to.
    int amt = 0;
    for (int i = 0; i < K; i++) {
        if (cows[i] > cows[K]) {
            amt = i-1;
            int another = i == 0 ? 0 : 1;
            for (int x = i+1; cows[x] < cows[K]; x++) {
                another++;
            }
            cout << max(amt, another) << "\n";
            return;
        }
    }
    amt = 0;
    for (int i = K+1; i < N; i++) {
        if (cows[K] > cows[i]) { amt++; }
        else { break; }
    }
    cout << amt + K << "\n";
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}