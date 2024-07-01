#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
vector<ll> start; //the first decrease starts at s here
vector<ll> res;
void solve() {
    int N; cin >> N;
    v.clear();
    v.resize(N);
    start.clear();
    start.resize(N);
    res.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    start[N - 1] = 0;
    ll time = v[N - 1];
    res[N - 1] = v[N - 1];
    //there are always like lulls in the thing
    //pauses that occur at different times
    //we need to check which of the pauses happen
    for (int i = N - 2; i >= 0; i--) {
        //if it is smaller than the previous one, we definitely have a pause
        //then it can decrease up to previous one and follow the time of that
        //if it is larger
        //wait it might not be trivial
        //we should try to say when we reach the next one's height so it knows where
        //okay but then for the ones smaller how are they affected
        //does small finish at the same time?
        //small finishes at +1 i think
        //when it starts decreasing
        //wait wtf is delay anyway
        if (v[i] > v[i+1]) {
            res[i] = max((ll)v[i], res[i+1] + 1);
            time = max(time, res[i]);
        }   else if (v[i] <= v[i + 1]) {
            //otherwise its always theirs plus one
            //wait what about equals?
            res[i] = res[i+1] + 1;
            time = max(time, res[i]);
        }
    }
    // for (int i = 0; i < N; i++) {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";
    cout << time << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T) { T--; solve(); }
}