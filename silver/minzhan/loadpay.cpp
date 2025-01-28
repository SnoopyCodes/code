#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    long N, K, M; cin >> N >> K >> M;
    long s = 1, e = N + 1;
    //if x is larger he pays more takes more time
    while (s + 1 < e) {
        long X = (s + e) / 2;
        long days = 0;
        //start with value R / X
        //when does this value change?
        //in t days
        //(R - tV) / X >= V
        //R - tV >= XV
        //R - XV >= tV
        //R / V - X >= t
        long R = N;
        while (R / X > M && R > 0) {
            long V = R / X;
            long t = R / V - X;
            t++;
            days += t;
            R -= t * V;
        }
        if (R > 0) { days += (R - 1) / M + 1; }
        if (days <= K) { s = X; }
        else { e = X; }
    }
    //notes: forgot condition R > 0 which led to cursed things happening and confusion for ~20 minutes
    cout << s << "\n";
}