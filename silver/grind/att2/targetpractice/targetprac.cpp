#include <bits/stdc++.h>

using namespace std;
vector<bool> targets;
vector<int> instruct;
int T, C;
struct off {
    int offset;  //what does it start at
    map<int, int> hits;  //target at i hit this many times left
    map<int, int> when;  //at instruct i we hit this this target
};
void sim(off& o) {  //this sets up map
    int pos = C + o.offset;
    int cnt = 0;
    for (int i = 0; i < C; i++) {
        if (instruct[i] == 0) {
            if (pos >= 0 && pos < 2 * C + 1 && targets[pos]) {
                o.hits[pos]++;
                cnt++;
                o.when[i] = pos;
            }
        }   else {
            pos += instruct[i];
        }
    }
}
void rem(off& o, int i) {
    if (o.when.count(i)) {
        int targ = o.when[i];
        o.hits[targ]--;
        if (o.hits[targ] <= 0) {
            o.hits.erase(targ);
        }
    }
}
void killt(off &o, int t) {
    if (o.hits.count(t)) {
        o.hits.erase(t);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> T >> C;
    targets.resize(2 * C + 1);
    instruct.resize(C);
    for (int i = 0; i < T; i++) {
        int pos;
        cin >> pos;
        targets[pos + C] = true;
    }
    string s; cin >> s;
    for (int i = 0; i < C; i++) {
        if (s[i] == 'L') {
            instruct[i] = -1;
        }   else if (s[i] == 'R') {
            instruct[i] = 1;
        }
    }
    off l2; l2.offset = -2;
    off l1; l1.offset = -1;
    off r1; r1.offset = 1;
    off r2; r2.offset = 2;
    sim(l2); sim(l1); sim(r1); sim(r2); 
    int best = 0;
    int curhit = 0;
    int pos = C;
    for (int i = 0; i < C; i++) {
        rem(l2, i);
        rem(l1, i);
        rem(r1, i);
        rem(r2, i);
        if (instruct[i] == 0) {
            best = max(best, curhit + (int)l1.hits.size());
            best = max(best, curhit + (int)r1.hits.size());
            if (targets[pos]) {
                curhit++;
                targets[pos] = false;
                killt(l2, pos);
                killt(l1, pos);
                killt(r1, pos);
                killt(r2, pos);
            }
        }   else if (instruct[i] == 1) {
            best = max(best, curhit + (int) l1.hits.size() +
            (pos > 0 && targets[pos] && !l1.hits.count(pos)));
            best = max(best, curhit + (int) l2.hits.size());
            pos += instruct[i];
        }   else {
            best = max(best, curhit + (int) r1.hits.size() +
            (pos < 2 * C && targets[pos] && !r1.hits.count(pos)));
            best = max(best, curhit + (int) r2.hits.size());
            pos += instruct[i];
        }
    }
    best = max(best, curhit);
    cout << best << "\n";
}