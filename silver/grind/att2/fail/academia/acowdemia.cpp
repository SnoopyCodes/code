#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, K, L;
vector<int> cites;
bool valid(int g) {
    ll total = 0;
    int first = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (cites[i] < g) { first = i; break; }
    }
    if (first == -1 || g <= (N-1 - first)) { return true; }  //should work
    int needed = g - (N - 1 - first);
    if (first - needed + 1 < 0) { return false; }
    if (g - cites[first - needed + 1] > K) { return false; }
    for (int i = first - needed + 1; i <= first; i++) {  //these are the papers we will try to cite
        total += g - cites[i];
    }
    return total <= (ll)K * L;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> L;
    cites.resize(N);
    //binary search on the h-index
    //we can write K papers and we want h-index of h
    //sort papers by current citations
    //we can just actually binary search on the last paper we don't cite
    //so theres that
    //then we only need to check how many citations we are missing
    //if the max citations needed for a single paper isnt more than K then it is fine
    //and as long as there aren't more than K * L overall we're fine
    //wait but we only need h papers with the same
    //so we can binary search on h first as we are doing
    //and then linear search on the first citation less than h citations
    //and then we know how many papers work for it already
    //if its greater than 
    for (int i = 0; i < N; i++) {
        cin >> cites[i];
    }
    sort(cites.begin(), cites.end());
    int s = 0, e = 1e5+1;
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (valid(m)) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}