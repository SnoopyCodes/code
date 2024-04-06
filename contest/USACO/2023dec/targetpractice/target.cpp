#include <bits/stdc++.h>

using namespace std;
vector<bool> targets;
vector<int> oned;
vector<bool> visited;
vector<int> commands;
struct Time {  //what time we used one, and which ones we turn off
    int time;
    vector<int> off;
};
vector<Time> def;
vector<vector<int>> pfx;
vector<vector<int>> changes;
void simdef(int start) {  //starting position
    for (int i = 0; i < commands.size(); i++) {
        cout << start << endl;
        start += commands[i];
        if (commands[i] == 0 && targets[start] && !visited[start]) {
            visited[start] = true;
            oned[start] = i+1;
            def[i].time = i+1;
        }
    }
}
void sim(int start) {
    for (int i = 0; i < commands.size(); i++) {
        start += commands[i];
        if (start < 0 || start > targets.size()) { continue; }
        if (commands[i] == 0 && targets[start] && !visited[start]) {
            visited[start] = true;
            if (oned[start] != 0) {
                def[oned[start]-1].off.push_back(2+start-commands.size());
            }
            changes[2+start-commands.size()][i] = i+1;
        }
    }
}
int main() {
    //i need to reset; its becoming too convoluted
    //so first
    //make 5 arrays saying what happens if stuff shifts over
    //right
    //we should use objects to check that when this default turns off, 
    //we turn these other things on
    //but the point is by the time 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, C; cin >> T >> C;
    targets.resize(2 * C);  //locatiosn along number line
    oned.resize(2 * C);
    commands.resize(C);
    def.resize(T);
    visited.resize(2 * T);
    pfx.resize(5, vector<int>(T+1));
    changes.resize(5, vector<int>(T));
    for (int i = 0; i < T; i++) { int loc; cin >> loc; targets[loc+C] = true; }
    string s; cin >> s;
    for (int i = 0; i < C; i++) {
        if (s[i] == 'L') { commands[i] = -1; }
        else if (s[i] == 'R') { commands[i] = 1; }
    }
    simdef(C);
    visited.clear(); visited.resize(2 * T);
    sim(C-2);
    visited.clear(); visited.resize(2 * T);
    sim(C-1);
    visited.clear(); visited.resize(2 * T);
    sim(C+1);
    visited.clear(); visited.resize(2 * T);
    sim(C+2);
    for (int j = 0; j < 5; j++) {
        if (j == 2) { continue; }
        for (int i = 1; i < T+1; i++) {
            pfx[j][i] = pfx[j][i-1] + changes[j][i-1];  //for every index i it contains the sums up to but not including that
        }
    }
    int best = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2) { continue; }
        best = max(best, pfx[i][T]);
    }
    int sum = 0;  //will hold default
    int start = 0; //position
    vector<int> dec(5);
    for (int i = 0; i < C; i++) {
        //so first consider default case
        start += commands[i];
        if (commands[i] == -1) {
            //try firing, moving to the right
            //R, RR
            best = max(best, sum + pfx[3][T] - pfx[3][i+1] + dec[3]);
            best = max(best, sum + pfx[4][T] - pfx[4][i+1] + dec[4]);
        }
        if (def[i].time != 0) {
            best = max(best, sum + pfx[1][T] - pfx[1][i+1] + dec[1]);
            best = max(best, sum + pfx[3][T] - pfx[3][i+1] + dec[3]);
        }
        if (commands[i] == 1) {
            //try firing, moving to right
            //l, ll
            best = max(best, sum + pfx[1][T] - pfx[1][i+1] + dec[1]);
            best = max(best, sum + pfx[0][T] - pfx[0][i+1] + dec[0]);
        }
        if (def[i].time != 0) { //increases
            sum++;
        }
        for (int x : def[i].off) {
            dec[x]--;
        }
    }
    best = max(best, sum);
    cout << best << "\n";
    //if we have our little pfx arrs and we can find which ones work before we make a change that helps a lot
    //basically when we make our pfx arrs
    //and then we hit a target if that target has been hit by bessie in default, then figure out when that happened
    //then we can have sets instead of pfx sum arrays? 
}