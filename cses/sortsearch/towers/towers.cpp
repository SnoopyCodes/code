#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //just keep a max tower map
    //this requires strategy
    //we should choose the tower with the smallest size already?
    int amt = 0;
    multiset<int> towers;  //size of top
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        if (towers.upper_bound(k) == towers.end()) { towers.insert(k); }
        else {
            towers.erase(towers.upper_bound(k));
            towers.insert(k);
        }
    }
    cout << towers.size() << "\n";
}