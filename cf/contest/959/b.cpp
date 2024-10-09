#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    string s; cin >> s;
    string t; cin >> t;
    vector<bool> bs(N);
    vector<bool> ts(N);
    for (int i = 0; i < N; i++) {
        bs[i] = s[i] == '1';
        ts[i] = t[i] == '1';
    }
    if (bs[0]) { cout << "YES" << "\n"; return; }
    if (bs[0] != ts[0]) { cout << "NO" << "\n"; return; }
    for (int i = 1; i < N; i++) {
        if (bs[i] == ts[i]) {

        }
    }
    //i dont get it
    //so basically xor the start to itself
    //okay
    //so if the first is 1 print 1
    //bc it can change anything
    //
    //we shouldn't change anything already working
    //ok so 
    //so the beginning
    //just start from the beginning and slam your way up
    //bruh how do i do this
    //just greeedy it idc
    //wait idek how to greedy it

}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}