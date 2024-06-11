#include <bits/stdc++.h>

using namespace std;
int power[10];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    power[0] = 1;
    for (int i = 1; i < 10; i++) { power[i] = 9 * power[i-1]; }
    //advantages: there are 9! orientations, which is like 362880 possiblities
    //we should code this into a bitmask
    //or like
    //where we bring stuff to
    //the 9th power? idk
    
    //ok i was going to not do this but lets just do this bc the other is just basic dp 
    //so what do we write
    
    int fac = 362880;
    vector<int> dist(fac+1, INT_MAX);
    int cur = 0;
    for (int i = 0; i < 9; i++) {
        cur *= 9;
        int d; cin >> d;
        cur += d;
    }
    dist[cur] = 0;
    queue<int> q;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        //now move everything

    }
    cout << cur << "\n";
}