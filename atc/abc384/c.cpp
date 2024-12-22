#include <bits/stdc++.h>

using namespace std;

vector<int> scores;

int go(int x) {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        if (x & 1 << i) { res += scores[i]; }
    }
    return res;
}
string buh(int x) {
    string res = "";
    for (int i = 0; i < 5; i++) {
        if (x & 1 << i) { res += (char) (65 + i); }
    }
    return res;
}

bool comp(int i, int j) {
    int is = go(i);
    int ij = go(j);
    if (is == ij) {
        string iss = buh(i);
        string jss = buh(j);
        return iss < jss;
    }
    return is > ij;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    scores.resize(5);
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
    }
    //print bitmasks
    vector<int> bm;
    for (int i = 1; i < 32; i++) {
        bm.push_back(i);
    }
    sort(bm.begin(), bm.end(), comp);
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 5; j++) {
            if (bm[i] & 1 << j) { cout << (char) (65 + j); }
        }
        cout << "\n";
    }
}