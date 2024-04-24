#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> coins;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    coins.resize(N);
    for (int &x : coins) {
        cin >> x;
    }
    sort(coins.begin(), coins.end());
    ll cur = 0;
    int nxt = 0;
    for (int i = 0; i < N; i++) {
        if (coins[i] > cur + 1) { break; }
        cur += coins[i];
        if (coins[i] == 1 << nxt) { nxt++; }
    }
    cout << cur + 1 << "\n";
    //okay lets say we have some cur. this means for all nums less than cur we covered
    //if we add a sum x, we cover the next x if cur >= x - 1
    //if not, then what?
    //
}