#include <bits/stdc++.h>

using namespace std;
vector<array<int, 3>> grazings;
vector<array<int, 3>> cows;
bool comp(array<int, 3> a1, array<int, 3> a2) {
    return a1[2] < a2[2];
}
bool trav(int i, int j) {
    int t = abs(cows[i][2] - grazings[j][2]);
    long long dist = (long long) (cows[i][0] - grazings[j][0]) * (cows[i][0] - grazings[j][0])
                    + (long long) (cows[i][1] - grazings[j][1]) * (cows[i][1] - grazings[j][1]);
    return (long long) t * t >= dist;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int G, N; cin >> G >> N;
    grazings.resize(G);
    for (int i = 0; i < G; i++) {
        cin >> grazings[i][0] >> grazings[i][1] >> grazings[i][2];
    }
    //okay wait
    //if a cow can make it to one grazing, it can make it to all of them
    //so its always optimal to check the 2 grazings closest in time to it
    sort(grazings.begin(), grazings.end(), comp);
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    sort(cows.begin(), cows.end(), comp);
    int cow = 0;
    int ans = 0;
    for (int lg = -1; lg < G; lg++) {
        while (cow < N && (lg + 1 == G || cows[cow][2] <= grazings[lg+1][2])) {
            if ((lg == -1 || trav(cow, lg)) && (lg == G - 1 || trav(cow, lg + 1))) {
                //can travel
                //but we're saying it can't for some reason
                ans++;
            }
            cow++;
        }
    }
    cout << N - ans << "\n";

}