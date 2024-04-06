#include <bits/stdc++.h>

using namespace std;
vector<bool> targets;
vector<vector<int>> adj;  //for this target, when we hit it, the ones that will later hit it are activated
vector<int> commands;
vector<int> def;
int sim(int start, int instruction, bool freedom) {
    if (instruction == commands.size()) { return 0; }
    if (!freedom) {
        start += commands[instruction];
        if (commands[instruction] == 0 && targets[start]) { return 1 + sim(start, instruction+1, false); }
        else { return sim(start, instruction+1, false); }
    }
    int best = 0;
    if (commands[instruction] == -1) {
        
    }
    int add = 0;

    
}
int main() {
    cout << "hi";
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, C; cin >> T >> C;
    targets.resize(2 * C);  //locatiosn along number line
    commands.resize(T);
    for (int i = 0; i < T; i++) { int loc; cin >> loc; targets[loc + C] = true; }
    string s; cin >> s;
    for (int i = 0; i < C; i++) {
        if (s[i] == 'L') { commands[i] = -1; }
        else if (s[i] == 'R') { commands[i] = 1; }
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < C; j++) {

        }
    }
    //what if we use convergence?
    //like start with all 5 off
    //5 pointers
    //as we move through the array we only keep the 5 best at that point?
    //thats a greedy alg though- does it work? i dont think so
}