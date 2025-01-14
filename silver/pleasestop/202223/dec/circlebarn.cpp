#include <bits/stdc++.h>

using namespace std;

vector<int> turns;

void solve() {
    int N; cin >> N;
    int jr = 2e9, jt = N, nr = 2e9, nt = N;
    for (int i = 0; i < N; i++) {
        int cows; cin >> cows;
        if (cows % 4 == 0) {
            if (nr > turns[cows]) {
                nr = turns[cows];
                nt = i;
            }
        }   else {
            if (jr > turns[cows]) {
                jr = turns[cows];
                jt = i;
            }
        }
    }
    //OKAY WHY DOES NR < NT GIVE MORE POINTS THAN JR < NT WTF
    //get a test case that breaks nr < nt and it should break jr < nt then!
    //???
    //literally what is happening
    //1 4 25 25 4 7 breaks my code
    //but it passes more tc than when i have code to fix it
    //it must be my calculation is inaccurate tehn!
    if (jr < nr || jr == nr && jt < nt) {
        cout << "Farmer John" << "\n";
    }   else {
        cout << "Farmer Nhoj" << "\n";
    }
    //our precalculation is accurate, the only thing is the comparison is inaccurate
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int maxv = 5e6;
    turns.resize(maxv + 1);
    vector<int> sieve(maxv + 1);
    turns[1] = 1;
    int max1 = 1, max3 = 3;
    for (int i = 2; i <= maxv; i++) {
        if (i % 4 == 0) { turns[i] = i / 4 + 1; }
        else if (i % 2 == 0) { turns[i] = i / 4 + 1; }
        else {
            if (i % 4 == 1) {
                turns[i] = 1 + turns[i - max1];
            }   else {
                turns[i] = 1 + turns[i - max3];
            }
        }
        if (sieve[i]) { continue; }
        turns[i] = 1;
        if (i % 4 == 1) {
            max1 = i;
        }   else if (i % 4 == 3) {
            max3 = i;
        }
        for (int j = 2 * i; j <= maxv; j += i) {
            sieve[j] = true;
        }
    }
    int T; cin >> T; while(T--) { solve(); }
}