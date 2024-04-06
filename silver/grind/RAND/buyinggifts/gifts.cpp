#include <bits/stdc++.h>

using namespace std;
struct Gift {
    int a, b, s;
};
vector<Gift> ag;
vector<Gift> bg;
bool compa(Gift g1, Gift g2) {
    return g1.a > g2.a;
}
bool compb(Gift g1, Gift g2) {
    return g1.b > g2.b;
}
//i made an account to submit this goofy solution lmao
//no data structures but covers stuff repeatedly
//basically sort both gifts in descending gift price
//and then 2p down them
//if at any point we stop considering a gift in a that is in the same department
//as gift b then we just stop (because one of the two must be bought and we can't have our selected a and b pointers)
//my code is actual garbage though 
void solve() {
    int N; cin >> N;
    ag.resize(N);
    bg.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        Gift g = {a, b, i};
        ag[i] = g;
        bg[i] = g;
    }
    sort(ag.begin(), ag.end(), compa);
    sort(bg.begin(), bg.end(), compb);
    int a = 0, b = 0;
    int mindist = INT_MAX;
    while (a < N && b < N) {
        if (ag[a].b > bg[b].b) { break; }  //if our b was passed by already its over
        bool valid = true;
        bool validn = true;
        while (b < N && bg[b].b > ag[a].a) {
            if (bg[b].s == ag[a].s) { validn = false; b++; continue; }  //if we don't select gift a we stop after this (large loopo) iteration
            mindist = min(mindist, bg[b].b - ag[a].a);
            if (bg[b].a > ag[a].a) { valid = false; break; }  //if we dont select gift b we stop immediately
            b++;
        }
        if (!valid) { break; }
        int prev = b;
        while (b < N && ag[a].a - bg[b].b < mindist) {
            if (bg[b].s == ag[a].s) { b++; continue; }  //this can be compared with other stuff later so no need to stop
            mindist = min(mindist, ag[a].a - bg[b].b);
            b++;
        }
        if (!validn) { break; }
        b = prev;
        a++;
    }
    //repeat code for other pointer direction :/
    a = 0, b = 0;
    while (a < N && b < N) {
        if (bg[b].a > ag[a].a) { break; }
        bool valid = true;
        bool validn = true;
        while (a < N && ag[a].a > bg[b].b) {
            if (bg[b].s == ag[a].s) { validn = false; a++; continue; }
            mindist = min(mindist, ag[a].a - bg[b].b);
            if (ag[a].b > bg[b].a) { valid = false; break; }  
            a++;
        }
        if (!valid) { break; }
        int prev = a;
        while (a < N && bg[b].b - ag[a].a < mindist) {
            if (bg[b].s == ag[a].s) { a++; continue; }
            mindist = min(mindist, bg[b].b - ag[a].a);
            a++;
        }
        if (!validn) { break; }
        a = prev;
        b++;
    }
    cout << mindist << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}