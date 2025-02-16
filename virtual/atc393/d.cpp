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
    int N; cin >> N;
    vec<int> diff(N + 1);
    vec<int> seq(N);
    int cnt = 0;
    long cur = 0;
    for (int i = 0; i < N; i++) {
        char x; cin >> x;
        seq[i] = x;
        if (x == '0') { continue; }
        cur += i - cnt;
        diff[i - cnt]++;
        cnt++;
    }
    //...
    //we will never swap 1's
    //start from 0 and say we will cramp it
    //then we can form a difference array
    //basically each of them have like a dist from start
    //and at some point they start switching
    //originally its like -1, -1 every time getting closer but at some point it starts getting further
    //which is at diff?
    //this is ternary search but i dont rlly wanna
    //long long?
    //got one more case somehow..
    int far = 0;
    long ans = cur;
    for (int i = 0; i <= N - cnt; i++) {
        far += diff[i];
        cur += far * 2;
        cur -= cnt;
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}