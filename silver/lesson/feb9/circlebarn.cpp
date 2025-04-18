#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int M;
int f(int x) { return (x+M) % M; }

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;M = N;
    vector<int> cows(N);
    long target = 0;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        target += cows[i];
    }
    //3 -1 -1 0 -1 -1 1
    //2 + 4 + 5 + 2 = 13
    //6 + 1 + 2 + 4 = 13
    //if the prefix sum array is nonnegative at all points from a start
    //then legal, perfectly legal
    //therefore an optimal sequence is taking min prefix subarray and moving it to beginning
    target /= N;
    for (int i = 0; i < N; i++) {
        cows[i] -= target;
    }
    int worst = 0;
    long worst_sum = cows[0];
    long sum = cows[0];
    for (int i = 1; i < N; i++) {
        sum += cows[i];
        if (sum < worst_sum) {
            worst = i;
            worst_sum = sum;
        }
    }
    sum = 0;
    long ans = 0;
    for (int i = f(worst + 1); i != worst; i = f(i+1)) {
        sum += cows[i];
        ans += sum;
    }
    cout << ans << "\n";
}