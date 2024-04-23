#include <bits/stdc++.h>

using namespace std;
const int sz = 8;
vector<vector<bool>> block(sz, vector<bool>(sz, false));
vector<array<int, 2>> placed;
vector<bool> row(sz);
vector<bool> slash(sz * 2 - 1);
vector<bool> lslash(sz * 2 - 1);
int total = 0;  //int trust
void run(int x) {
    if (x == sz) { total++; return; }
    for (int i = 0; i < sz; i++) {
        if (row[i]) { continue; }
        if (slash[i + x]) { continue; }
        if (lslash[x - i + sz - 1]) { continue; }
        if (block[i][x]) { continue; }
        row[i] = true;
        slash[i + x] = true;
        lslash[x - i + sz - 1] = true;
        run(x+1);
        row[i] = false;
        slash[i + x] = false;
        lslash[x - i + sz - 1] = false;
        
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
    cout << total << "\n";
}