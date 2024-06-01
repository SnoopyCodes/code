#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    //note we can only win a limited number of points
    //isn't this just a basic runthrough
    //just overlay the intervals
    //then take whichever is highest on each day
    //is that not optimal
    //oh my days a project is not one day :skull:
    //oh it ending on a certain thing is obvious
    //yay
    //then first dp is obvious?
    //sort by the like time
    //do we only need to sort by start time
    //this is sort of lis
    //so basically the idea is dp represents best money at event start x
    //
    vector<array<int, 3>> projects(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    projects[N][0] = INT_MAX;
    //if we use a map it could become really scuffed
    //put in a binary search
    //you know what we should just use a map!
    //we should probably like use a vector simulating a stack or something
    sort(projects.begin(), projects.end());
    vector<ll> best(N + 1);
    ll cur = 0;
    for (int i = 0; i < N; i++) {
        cur = max(best[i], cur);
        int t = projects[i][1]; //find lower bound
        int s = -1, e = N;
        while (s + 1 < e) {  //find first element > t
        //crying sobbing dying
            int m = (s + e) / 2;
            if (projects[m][0] <= t) {
                s = m;
            }   else {
                e = m;
            }
        }
        best[e] = max(best[e], cur + projects[i][2]);
    }
    cout << best[N];
