#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = 0;
    vector<int> llength(N);
    while (r < N) {
        if (v[r] - v[l] <= K) { r++; }
        else { llength[l] = r - l; l++; }
    }
    vector<int> rlength(N);
    l = N - 1, r = N - 1;
    while (l >= 0) {
        if (v[r] - v[l] <= K) { l--; }
        else { rlength[r] = r - l; r--; }
    }
    
    //for each index find the integer r such that r is the largest size within k of index
    //then check whether we need to use the 2 largest nonoverlapping sizes within the vector, or the individual largest plus overlapped 
}