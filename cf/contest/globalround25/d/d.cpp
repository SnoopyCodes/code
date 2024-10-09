#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    ll N, K; cin >> N >> K;
    vector<int> stalls(60);
    //this looks better
    //we can stop alice whenever we want
    //but so many jewels
    //find remainders that work basically..
    //dude how tf
    //how do we find remainders?
    //when is it impossible?
    //figure out how many we want at each step
    //how many jewels do we want to do at each step?
    //wait this is hard

    cout << "YES" << "\n";
    for (int i = 0; i < 60 && stalls[i] > 0; i++) {
        cout << stalls[i];
        if (i < 59 && stalls[i+1] != 0) { cout << " "; }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}