#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
    vector<int> reconstruct(N);
    vector<pair<int, int>> each(N);
    //start with min = 0 at a[0]
    //set up mins and maxes
    //and then just check
    each[0].first = 0, each[0].second = 0;
    reconstruct[0] = 0;
    for (int i = 1; i < N; i++) {  //add 
        //first figure out whether the direction is positive or negative?
        //if the direction is negative (past 0) when we're going positive we can just stick it positive i think
        //how do we find the direction?
        //are we really figuring out the correct direction?
        //the idea is the same thing, but in reverse
        //okay
        int candidate = reconstruct[i-1] + v[i-1][1];
        bool valid = true;
        for (int j = 0; j < i; j++) {
            if (candidate > each[j].second) {
                if (candidate - each[j].first != v[j][i-j]) { valid = false; break; }
            }   else if (candidate < each[j].first) {
                if (each[j].second - candidate != v[j][i-j]) { valid = false; break; }
            }
        }
        if (!valid) { candidate = reconstruct[i-1]-v[i-1][1]; }
        reconstruct[i] = candidate;
        for (int j = 0; j < i; j++) {
            each[j].second = min(each[j].second, reconstruct[i]);
            each[j].first = min(each[j].first, reconstruct[i]);
        }
        each[i].first = reconstruct[i], each[i].second = reconstruct[i];
    }
    for (int i = 0; i < N-1; i++) {
        cout << reconstruct[i] << " ";
    }
    cout << reconstruct[N-1];
}