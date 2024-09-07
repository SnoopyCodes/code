#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<vector<int>> pfx(26, vector<int>(N + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            pfx[j][i + 1] = pfx[j][i];
        }
        pfx[s[i] - 'a'][i+1]++;
    }
    //lets consider that between l and r it increases a set of characters x times
    //to form an irreducible anagram we need to ensure that at no time is
    //the pfxs of every char the same. if there is more than one distinct character
    //this can be done i think
    //aba
    //aab ? this has none therefore my algorithm is wrong
    //uhhh
    //if its only 2 then we need to check
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r; l--;
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            diff += pfx[i][r] - pfx[i][l] != 0;
        }
        bool works = diff > 2 || r - l < 2;
        if (diff == 2) {  //works iff distinct at the ends
            works |= s[l] != s[r - 1];
        }
        if (works) { cout << "Yes" << "\n"; }
        else { cout << "No" << "\n"; }
    }
}