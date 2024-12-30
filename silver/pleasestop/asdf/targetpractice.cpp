#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T, C; cin >> T >> C;
    vector<bool> targets(2 * C + 5);
    for (int i = 0; i < T; i++) {
        int x; cin >> x;
        targets[x + C + 2] = true;
    }
    vector<int> commands(C);
    for (int i = 0; i < C; i++) {
        char c; cin >> c;
        if (c == 'L') { commands[i]--; }
        else if (c == 'R') { commands[i]++; }
    }
    vector<vector<int>> hits(5, vector<int>(2 * C + 5));  //number of hits on each target per offset
    vector<int> count(5);  //number of active hits in each one
    int pos = C + 2;
    for (int i = 0; i < C; i++) {
        pos += commands[i];
        if (!commands[i]) {  //we fire
            for (int j = 0; j < 5; j++) {
                if (targets[pos + j - 2]) {
                    if (!hits[j][pos + j - 2]) {
                        count[j]++;  //first hit
                    }
                    hits[j][pos + j - 2]++;
                }
            }
        }
    }
    pos = C + 2;
    int ans = count[2];
    int cur = 0;
    vector<bool> curhit(2 * C + 5);
    for (int i = 0; i < C; i++) {
        //remove this command from each of the offsets so it counts from next onwards
        //
        for (int j = 0; j < 5; j++) {
            if (!commands[i] && targets[pos + j - 2] && hits[j][pos + j - 2]) {
                hits[j][pos + j - 2]--;
                if (!hits[j][pos + j - 2]) {
                    count[j]--;
                }
            }
        }
        //if we change to hitting a target- make sure we haven't hit it before
        if (commands[i] == -1) {  //change to 3, 4; F, R
            ans = max(ans, cur + (targets[pos] && !hits[3][pos] && !curhit[pos]) + count[3]);
            ans = max(ans, cur + count[4]);
        }   else if (commands[i] == 1) {  //change to 1, 0; F, L
            ans = max(ans, cur + (targets[pos] && !hits[1][pos] && !curhit[pos]) + count[1]);
            ans = max(ans, cur + count[0]);
        }   else {  //change to 1, 3
            ans = max(ans, cur + count[1]);
            ans = max(ans, cur + count[3]); 
        }
        if (!commands[i] && targets[pos]) {
            if (!curhit[pos]) { cur++; }
            curhit[pos] = true;
            //we can never hit this one again in any of the others so remove those
            for (int j = 0; j < 5; j++) {
                if (hits[j][pos]) {
                    hits[j][pos] = 0;
                    count[j]--;
                }
            }
        }
        pos += commands[i];
    }
    cout << ans << "\n";
}