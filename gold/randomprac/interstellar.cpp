#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define AD(a, b) ((a + b) % MOD + MOD) % MOD
#define SB(a, b) AD(a, -b)

int i = 5;
int *ten;
int y = i[ten];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    /*
    dp for ways to set to blue or white
    if we're red just set to 0
    we might need sums for parities
    we also only transition from blues/whites

    suppose position i is colored white

    sum dp[i - 2, i - 4, i - 6, ...last_forced_color] * 2 (we can color or not color)

    suppose the last forced color is red
    query for the closest blue after that and we know our filling limits

    suppose the last forced color is blue
    query for the closest red after that
    then another blue

    */
    vt<int> dp(N);
    vt<int> prev_force; //limit to size 3
    vt<ii<2>> psum(N + 1);
    for (int i = 1; i < N; i++) {
        psum[i + 1][i & 1 ^ 1] = psum[i][i & 1 ^ 1];
        if (s[i] == 'R') {
            if (!prev_force.size() || s[prev_force.back()] != 'R') { prev_force.add(i); }
            if (size(prev_force) > 3) { prev_force.erase(begin(prev_force)); }
            psum[i + 1][i & 1] = psum[i][i & 1];
            continue;
        }
        int j = prev_force.size() ? prev_force.back() : -1;
        int amt = SB(psum[i][i & 1], psum[j + 1][i & 1]);
        if (s[i] == 'W') { amt = AD(amt, amt); }
        dp[i] = AD(dp[i], amt);

        //logik time
        int bl = -1, r = -1, br = -1;
        bool closest_is_blue = !prev_force.size() || s[prev_force.back()] == 'B';
        if (closest_is_blue) {
            br = prev_force.size() ? prev_force.back() : -1;
            r = prev_force.size() > 1 ? prev_force[prev_force.size() - 2] : -1;
            bl = size(prev_force) > 2 ? prev_force[0] : -1;

        }   else {
            r = prev_force.size() ? prev_force.back() : -1;
            bl = prev_force.size() > 1 ? prev_force[prev_force.size() - 2] : -1;
            if (~r && (i & 1 == r & 1)) { r--; }
            //r provides an upper bound for how far we can query from
            //bl provides a lower bound
        }


        if (s[i] == 'B') {
            if (!prev_force.size() || s[prev_force.back()] != 'B') { prev_force.add(i); }
            if (size(prev_force) > 3) { prev_force.erase(begin(prev_force)); }
        }
        psum[i + 1][i & 1] = AD(psum[i][i & 1], dp[i]);
    }
    cout << dp[N - 1] << "\n";
}