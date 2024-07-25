#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, P; cin >> N >> P;
    vector<int> t1;
    string s; cin >> s;
    for (int i = 0; i < N; i++) {
        if (t1.empty() || t1[t1.size() - 1] != int(s[i]) - '1') {
            t1.push_back(int(s[i]) - '1');
        }
    }
    cin >> s;
    vector<int> t2;
    for (int i = 0; i < N; i++) {
        if (t2.empty() || t2[t2.size() - 1] != s[i] - '1') {
            t2.push_back(s[i] - '1');
        }
    }
    // cout << t1.size() << "\n";
    // for (int i = 0; i < t1.size(); i++) {
    //     cout << t1[i] << " ";
    // }
    // cout << "\n";
    // cout << t2.size() << "\n";
    // for (int i = 0; i < t2.size(); i++) {
    //     cout << t2[i] << " ";
    // }
    // cout << "\n";
    //we should make it so that
    //101010
    //010101
    //0 1 0 
    //we should remove until they are down to size 1
    //if we've swapped it what do we do
    //all 1's become 2 and all 2's become 1
    vector<array<int, 2>> moves;
    bool swapped = false;
    //we want to start with t1[0] != t1[-1]
    //if t1[0] == t1[-1]
    //if t2[-1] == t1[-1] then move it
    //otherwise distribute from t2
    if (t1.size() > 1 && t1[0] == t1[t1.size() - 1]) {
        if (t1[t1.size() - 1] == t2[t2.size() - 1]) {
            moves.push_back({1, 2});
            t1.pop_back();
        }   else {
            swapped = true;
            swap(t1, t2);
        }
    }
    vector<int> beaker;
    //first, do operations until t1 is down to 1
    //did it like
    //fail to
    //so first
    //if its the same
    //move the top
    while (t1.size() > 1) {
        //if we can add to the top of t2 we should probably do that?
        int top = t1[t1.size() - 1];
        t1.pop_back();
        if (top == t2[t2.size() - 1]) {
            moves.push_back({1, 2});
        }   else {
            if (beaker.empty()) { beaker.push_back(top); }
            moves.push_back({1, 3});
        }
    }
    while (t2.size() > 1) {
        int top = t2[t2.size() - 1];
        t2.pop_back();
        if (top == t1[t1.size() - 1]) {
            moves.push_back({2, 1});
        }   else {
            if (beaker.empty()) { beaker.push_back(top); }
            moves.push_back({2, 3});
        }
    }
    if (t1[0] == t2[0]) {
        moves.push_back({2, 1});
        t2.pop_back();
    }
    while (!beaker.empty()) {
        int top = beaker[beaker.size() - 1];
        beaker.pop_back();
        if (top == t1[0]) {
            moves.push_back({3, 1});
        }   else {
            moves.push_back({3, 2});
        }
    }
    cout << moves.size() << "\n";
    if (P-1)
    for (int i = 0; i < moves.size(); i++) {
        int s1 = moves[i][0], s2 = moves[i][1];
        if (swapped) {
            if (s1 < 3) { s1 = 3 - s1; }
            if (s2 < 3) { s2 = 3 - s2; }
        }
        cout << s1 << " " << s2 << "\n";
    }
    //1010
    //1010
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T) { T--; solve(); }
}