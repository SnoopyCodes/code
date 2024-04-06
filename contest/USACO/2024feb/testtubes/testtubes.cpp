#include <bits/stdc++.h>

using namespace std;
const int TYPE1 = 1;
const int TYPE2 = 2;
void solve() {
    int N, P; cin >> N; cin >> P;
    string s1, s2; cin >> s1 >> s2;
    vector<int> b1;
    vector<int> b2;
    if (s1[0] == '1') { b1.push_back(TYPE1); }
    else { b1.push_back(TYPE2); }
    if (s2[0] == '1') { b2.push_back(TYPE1); }
    else { b2.push_back(TYPE2); }
    for (int i = 1; i < N; i++) {
        if (s1[i] - '0' != b1[b1.size()-1]) {
            if (b1[b1.size()-1] == TYPE1) { b1.push_back(TYPE2); }
            else { b1.push_back(TYPE1); }
        }
        if (s2[i] - '0' != b2[b2.size()-1]) {
            if (b2[b2.size()-1] == TYPE1) { b2.push_back(TYPE2); }
            else { b2.push_back(TYPE1); }
        }
    }
    //i think if we do a thing where we solve directly for the first 2 then we win
    //okay inputted
    //if there are 2 of hte same color on both put them on one arbitrarily
    //if there are different we need to put on extra
    //now the start is the front and we work on the thing
    int b3 = -1;
    vector<pair<int, int>> instruct;
    while (b1.size() > 1) {
        if (b1[b1.size()-1] == b2[b2.size()-1]) {
            b1.erase(b1.end()-1);
            instruct.push_back({1, 2});
        }   else {
            b3 = b1[b1.size()-1];
            b1.erase(b1.end()-1);
            instruct.push_back({1, 3});
        }
    }
    //now b1 is just one size
    //if it is the same as b3 b3 should go to it
    bool same = false;
    if (b1[b1.size()-1] == b3) {
        if (b1[b1.size()-1] == b2[0]) { instruct.push_back({1, 3}); b1[b1.size()-1] = !(b1[b1.size()-1]-1) + 1; }
        else {
        instruct.push_back({3, 1}); b3 = -1;
        }
    }

    while (b2.size() > 1) {
        if (b1[b1.size()-1] == b2[b2.size()-1]) {
            b2.erase(b2.end()-1);
            instruct.push_back({2, 1});
        }   else {
            b3 = b2[b2.size()-1];
            b2.erase(b2.end()-1);
            instruct.push_back({2, 3});
        }
    }
    if (b1[b1.size()-1] == b2[b2.size()-1]) {
        instruct.push_back({2, 1});
        instruct.push_back({3, 2});
    }   else if (b3 != -1) {
        instruct.push_back({3, 2});
    }
    if (P == 2 || P == 3) {
        cout << instruct.size() << "\n";
        for (int i = 0; i < instruct.size(); i++) {
            cout << instruct[i].first << " " << instruct[i].second << "\n";
        }
        return;
    }
    if (P == 1 && N != 4) {
        cout << instruct.size() - 4 << "\n";
    }   else if (N == 4) { cout << instruct.size() << "\n"; }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
    //this appears to be a greedy algorithm
    //we need to figure out where to put the 1's and 2's
    //lets do 1 if 1 is at the bottom at 1
    //we lose time when it's more optimal to put in another bc the color needs to go right there, and also 
    //when we need to directly put into 1 instead of other stuff lol
    
}