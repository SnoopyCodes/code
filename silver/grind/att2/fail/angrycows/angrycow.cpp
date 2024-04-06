#include <bits/stdc++.h>

using namespace std;
vector<int> bales;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //
    //so first get the size
    //
    //there are 2 parts to this: finding the location and the radius
    //it does not do to choose the location with the largest gap in between htem
    //we must binary search on the radius
    //we need to check that on each interval 
    //it works
    //if we can say for bale i that if we have power p going a certain direction we will cover the whole thing
    //then we can check all the positions to put power into 
    //and then it works
    //but saying that we have power p going dir is kind of slow
    //actually its not that slow its dynamic programming!
    //yea ok but binary search
    //binary search on size AND location?
    //how does that work
    int N; cin >> N;
    bales.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bales[i];
    }
    sort(bales.begin(), bales.end());
    int s = 0, e = 1e9;
    while (e > s + 1) {
        
    }
}