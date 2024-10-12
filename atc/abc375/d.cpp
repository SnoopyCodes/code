#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    //this is a lot simpler than C i think
    //keep prefix and suffix sums
    //and base off of the central element
    //pf[i][j] = # of j's from 0 to i not including i itself!
    //sf[i][j] = # of j's from N to i including i.. harder to do?
    //try not including
    vector<vector<int>> pf(N + 1, vector<int>(26));
    vector<vector<int>> sf(N + 1, vector<int>(26));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            pf[i+1][j] = pf[i][j];
            //if i = 0, we are at N - i - 1, or N - 1
            //
            sf[N - i - 1][j] = sf[N - i][j];
        }
        pf[i+1][s[i] - 65]++;
        sf[N - i - 1][s[N - 1 - i] - 65]++;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            ans += (long long) pf[i][j] * sf[i+1][j];
        }
    }
    cout << ans << "\n";
}