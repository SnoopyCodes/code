#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //oh god no wtf oh god no
    int N, M; cin >> N >> M;
    //every pair of intervals themselves contribute to something?
    //build a counter for [min][len]
    //epic failure
    //let us iterate from M instead
    //for k and some min, find all that work
    //this looks doable, just hard
    //wait no its actually quite simple you just sum pairwise for interval start
    //
    vector<int> starts(M + 1);
    vector<int> ends(M + 1);
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        starts[s]++;
        ends[e]++;
    }
    vector<ll> diff(2 * M + 2);
    for (int i = 0; i <= M; i++) {  //start
        for (int j = 0; j <= M; j++) {  //end
        //hold on wait this requires *mathematics*
        //number of ways to combine, choose 2
            diff[i + j] += (long long) starts[i] * starts[j];
            diff[i + j + 1] -= (long long) ends[i] * ends[j];
        }
    }
    long long sum = 0;
    for (int i = 0; i <= 2 * M; i++) {
        sum += diff[i];
        cout << sum << "\n";
    }
}