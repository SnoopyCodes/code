#include <bits/stdc++.h>

using namespace std;
struct Diamond{
    int size, dist;
};
vector<Diamond> diamonds;
bool comp(Diamond d1, Diamond d2) {
    return d1.size < d2.size;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N; cin >> N;
    diamonds.resize(N);
    int K; cin >> K;
    for (int i = 0; i < N; i++) {
        cin >> diamonds[i].size;
    }
    sort(diamonds.begin(), diamonds.end(), comp);
    //precompute the most diamonds that fit for each starting point i.
    //can we even do that i think so actually using 2p
    //ok then what? how do we find the max sum that doesnt intersect?
    //start the second pointer just outside of the range of the first
    //what if we did both ways? does that tell us anything?
    //that tells us the max that including this diamond can have
    //
    int l = 0, r = 0;
    while (l != N) {
        while (r != N && diamonds[l].size + K >= diamonds[r].size) { r++; }
        diamonds[l].dist = r - l;
        l++;
    }
    l = 0, r = 0;
    int most = 0, rmax = 0;
    while (r != N) {
        while (l != r && l + diamonds[l].dist-1 < r) { rmax = max(rmax, diamonds[l].dist); l++; }
        if (l == 0) { l++; }
        l--;
        most = max(most, rmax + diamonds[r].dist);
        r++;
    }
    cout << most << "\n";
}