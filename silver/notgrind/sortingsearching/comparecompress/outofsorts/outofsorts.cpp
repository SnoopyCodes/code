#include <bits/stdc++.h>

using namespace std;
struct integers {
    int pos, val;
};
bool comp(integers i1, integers i2) {
    return i1.val < i2.val || (i1.val == i2.val && i1.pos < i2.pos);
}
vector<integers> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout);
    int N; cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].val;
        v[i].pos = i;
    }
    sort(v.begin(), v.end(), comp);
    int maxmove = 1;
    //so we can iterate through the vector and create another one, where v[i].first
    for (int i = 0; i < v.size(); i++) {
        maxmove = max(maxmove, 1+abs(i - v[i].pos));
        //worst case is all the same val which is pretty bad
        //
    }
    cout << maxmove;
    //so we need O(N) about
    //and we need to figure out how many iterations it is before the thing is completed.
    //each iteration it is guaranteed that from any range 0 to j for some iteration i,
    //the maximum of that iteration will be moved to the end. 
    //we may be able for range 0 to j iterating through j, see how many iterations it is before 0 through j is sorted
    //or work from backwards
    //arguably we may remove elements that have been sorted
    //we can also manually sort using quicksort and then get the max of the differences (or how many iterations until sorted)
    //not only that, though, we have to figure out duplicates.. if there are duplicates the problem is that quicksort arbitrarily moves them not really caring
    //
}