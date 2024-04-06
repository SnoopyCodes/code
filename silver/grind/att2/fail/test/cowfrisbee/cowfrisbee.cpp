#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int, int>> cows;
vector<int> taller;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    cows.resize(N);
    taller.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first;
        cows[i].second = i;
    }
    //we can very easily get O(N^2) on this
    //obviously we have one iterator (j) and then we need something to look at the 
    //ones from 0 to j
    //we have found the first index that each cow cannot throw past
    //we can do taht for throwing backwards as well quite easily
    //and then for each cow we can check
    //that between what we have covered
    //what we can use
    //we need the sum of the distances of the cows less than it that it can use
    //but only between it and a certain point
    //which would be prefix sums?
    //so for each pfx[i] we store the sum of the distances that go up to it
    {set<pair<int, int>> above;
    for (int i = N - 1; i >= 0; i--) {
        //find the upper bound in above
        auto it = above.upper_bound({cows[i]});
        if (it != above.end()) { taller[(*it).second] += (*it).second - i; }
        above.insert({cows[i]});
    }}
    //we can say for each one how many it was blocked from being with
    //pretty much?
    //if you could always go to the ones higher than you 
    //we would have
    //N-1 + N-2... + 0 = N(N-1) / 2
    //
    int delta = 0;  //how many cows we have so far
    for (int i = 0; i < N; i++) {

    }
}