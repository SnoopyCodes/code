#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //what is a long double
    int N; cin >> N;
    vec<vec<int>> die(N);
    vec<int> len(N);
    for (int i = 0; i < N; i++) {
        cin >> len[i];
        die[i].resize(len[i]);
        for (int j = 0; j < len[i]; j++) {
            cin >> die[i][j];
        }
        sort(die[i].begin(), die[i].end());
    }
    //10^-8...
    //calculate the probability of two dice i and j
    //chance of landing k = 1/len[i] * 1/len[j]
    //for all k
    //brute force go!
    //5000 * 100,000
    double ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            vec<int> di = die[i], dj = die[j];
            unordered_map<int, int> ini;
            unordered_map<int, int> inj;
            double res = 0;
            for (int x : di) { ini[x]++; }
            for (int x : dj) { inj[x]++; }
            for (auto [k, f] : ini) {
                res += (double) f / len[i] * inj[k] / len[j];
            }
            ans = max(res, ans);
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << "\n";
}