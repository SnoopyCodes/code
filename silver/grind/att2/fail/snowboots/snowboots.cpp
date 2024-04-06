#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> boots;
vector<int> tiles;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
    int N, B; cin >> N >> B;
    boots.resize(B);
    tiles.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> tiles[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> boots[i].first >> boots[i].second;
    }
    //then as we iterate backwards, we can store in a set
    //the distance required for boots with current strength s to get to the end
    //if we insert depth, stepdist
    //we need to find the nearest smaller element
    //lol i never know when to stop
    //ok we can't do it with this i think
    //if we iterate backwards, to get the minimum distance needed to travel we must
    //find in the ones we have already covered, the closest element with less or equal depth,
    //and then take hte min between the distance to them or their distance to the next
    //okay but if we use a set sorting by tile number
    //and insert from smallest to largest
    //when inserted we should look for smaller element closest to it
    //but how lol
    //oh
    //it requires working on the boots as well
    //ugh
}