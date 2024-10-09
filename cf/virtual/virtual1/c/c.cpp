#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int N = s.size();
    string better = "";
    vector<int> last(26, -1);
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        while (i+1 < N && s[i] == s[i+1]) {
            i++;
            cnt++;
        }
        if (cnt != 1) {
            i++;
        }
        better += s[i];
    }
    N = better.size();
    for (int i = N-1; i >= 0; i--) {
        //think think think
        //it cant be hard
        //if we delete segment l we remove l-1 points that need to be linked
        //wait but then we also skip over 2 deletions
        //therefore we've reduced # deletions by 2!
        //if initially we wanted n deletions.!
        //therefore we should always do the smallest intervals
        //therefore we actually just care about the smallest intervals
        //then how do we figure out if our intervals are deleted or not?
        //until we run out of intervals to delete pretty much
        //when we delete an interval we also delete any chance of those having any intervals
        //so we've deleted l intervals, and ourself
        //when we delete a total of 2n intervals we end
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}