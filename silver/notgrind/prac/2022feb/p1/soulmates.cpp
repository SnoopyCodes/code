#include <bits/stdc++.h>

using namespace std;

long long cost(long long c1, long long targ) {  //precondition is that c1 < targ, > targ / 2
    if (c1 == targ) { return INT_MAX - 100; }  //oops +1 makes it overflow
    long long baseline = targ - c1;  //most basic
    long long dummy = targ;
    long long overhead = 1;
    if (dummy % 2 != 0) { dummy--; overhead++; }  //needs to add one later as it comes up
    if (c1 % 2 != 0) { c1++; overhead++; }  //in order to be able...
    long long compare = cost(c1 / 2, dummy / 2) + overhead;
    return min(baseline, compare) + 1; //plus one as it doubles to go back up
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<long long, long long>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    //what are strategies that can be used in order to change these?
    //so first if 1 is less than half of 2 we can 
    //if its larger? /= 2 until less than half of 2, then employ strategies.
    for (int t = 0; t < N; t++) {
        long long c1 = cows[t].first; long long targ = cows[t].second;
        int ops = 0;
        while (c1 > targ) {
            if (c1 % 2 != 0){ c1++; ops++; }
            c1 /= 2; ops++;
        }
        while (c1 < targ / 2) {
            if (targ % 2 != 0) { targ--; ops++; }
            targ /= 2;
            ops++;
        }
        if (c1 == targ) { cout << ops << "\n"; continue; }
        //so xor will tell us where the diffs are
        //also i think we can make a recursive function evaluating the cost of- walking one by one to a "targ" or /=2 to look at another targ
        
        cout << cost(c1, targ)-1 + ops << "\n";
    }
}