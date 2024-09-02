#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("herding.in", "r", stdin);
    // freopen("herding.out", "w", stdout);
    int N; cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    //just sliding window bruh
    //not gonna bs bc im too lazy
    //wait cant be an endpoint
    //bruh i cannot read
    //then we need to find the 2 cows that either are like exactly or are not exactly
    //that works for best
    //what about worst?
    //
    sort(cows.begin(), cows.end());
    int i = 0, j = 1;
    int best = 0;
    int worst = N;
    while (i < N) {
        while (j < N && cows[j] < cows[i] + N) { j++; }
        if (j == N && cows[N - 1] - cows[i] < N - 1) { break; }
        int in_interval = j - i;
        best = max(best, j - i);  //wtf does this mean 
        worst = min(worst, j - i);
        i++;
    }
    //
    cout << N - best << "\n";
    cout << N - worst << "\n";
}