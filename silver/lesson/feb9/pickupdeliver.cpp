#include <bits/stdc++.h>

#define long int64_t

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //omg its catalan
    //unfortunately i have not studied the fast computation method..
    //nvm its not catalan lmfao
    long answer = 1;
    for (int i = 0; i < N; i++) {
        long ways = 0;
        // for (int j = 0; j <= 2 * i; j++) {
        //     ways += 2 * i + 1 - j;
        // }
        //sum (2 * i + 1) * (2 * i + 1)
        //subtract 1+2+3... 2 * i

        // ways = (2 * i + 1) * (2 * i + 1);
        // ways -= (2 * i) * (2 * i + 1) / 2;
        //(i + 1) * (2 * i + 1)
        ways = long(i + 1) * (2 * i + 1) % MOD;
        answer = (answer * ways) % MOD;
    }
    cout << answer << "\n";
}