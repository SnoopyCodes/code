#include <bits/stdc++.h>

using namespace std;
const int sz = 5;
vector<vector<bool>> block(sz, vector<bool>(sz, false));
vector<array<int, 2>> placed;
vector<bool> row(sz);
vector<bool> col(sz);
vector<bool> slash(sz);
vector<bool> bslash(sz);
int total = 0;  //int trust
long long blocked = 0;
void run(int x) {
    if (x == sz) { total++; return; }
    //very bad job
    //just argue on occupied things
    for (int i = 0; i < sz; i++) {
        if (row[i] || col[i]) { continue; }
        
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //classical recursion problem
    //oh wait but we can't place on some
    //alright then
    for (int i = 0; i < sz; i++) {
        string s; cin >> s;
        for (int j = 0; j < sz; j++) {
            if (s[j] == '*') { block[i][j] = true; }
        }
    }
    //consider instead the chessboard and each 64 squares
    //what if we 
    run(0);
    cout << blocked << "\n";
    cout << total << "\n";
}