#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<bool> broke;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int N, K, B;
    cin >> N >> K >> B;
    broke.resize(N);
    for (int i = 0; i < B; i++) {
        int index; cin >> index; index--;
        broke[index] = 1;
        //so we need to find a subarray such that everything inside is minimized.
        //start with 2 pointers i and j at both ends and work downwards?
        //because the thing has to be at least size K
        //prefix sums...
        //for each index you can probably get the next entire array length k with all of the 
    }
    int fix = 0;
    for (int i = 0; i < K; i++) {
        fix += broke[i];
    }
    int minfix = fix;
    for (int i = 1; i + K - 1 < N; i++) {
        if (broke[i-1]) { fix--; }
        if (broke[i+K - 1]) { fix++; }
        minfix = min(minfix, fix);
    }
    cout << minfix << "\n";

}