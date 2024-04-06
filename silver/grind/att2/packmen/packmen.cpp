#include <bits/stdc++.h>
using namespace std;
bool isAst[100000];
bool isPm[100000];
int N;
bool valid(int t) {
    int lastA = 0;  //the first asterisk that must be covered by the next pacman
    while (!isAst[lastA]) { lastA++; }
    bool yes = true;
    for (int i = 0; i < N; i++) {  //the packman
    //find the first pacman for which it is larger than lastA
        while (i < N && lastA < N && (!isPm[i] || i <= lastA)) {
            if (isPm[i]) {
                //is it possible that lastA is not reachable from i?
                lastA = i + t + 1;  //this covers up to here
            }
            i++;
        }
        while (lastA < N && !isAst[lastA]) { lastA++; }  //next asterisk
        if (lastA >= N) { return true; }
        if (i >= N) {  //if we didn't cover the rest, we didn't make it
            while (lastA < N) {
                if (isAst[lastA]) { return false; }
                lastA++;
            }
            return true;
        }
        if (i - lastA > t) { return false; }  //too far away
        lastA = max(i + t - 2 * (i - lastA), (t + i + lastA) / 2) + 1;  //we can cover up to at least here
        while (lastA < N && !isAst[lastA]) { lastA++; }  //find the first next asterisk, or be at i
        if (lastA >= N) { return true; }  //finished
    }
    while (lastA < N) {
        if (isAst[lastA]) { return false; }
        lastA++;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    {
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            isAst[i] = s[i] == '*';
            isPm[i] = s[i] == 'P';
        }
    }
    int s = 0, e = 2 * N;  //binary search on the minimum time needed
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (valid(m)) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
    //each packman is responsible for some number of asterisks
    //the optimal movement for each pacman is to choose a direction once, and only ever switch directions once
    //also, the game field is quite small, not 1e9... how can we use htis?
    //each asterisk can choose a pm
    //then each pm can find its closest and furthest away and find the time it takes to finish the route
    //not good
    //binary search instead on the time it takes 
    //then we can figure that out
}