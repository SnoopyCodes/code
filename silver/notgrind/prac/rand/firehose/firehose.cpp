#include <bits/stdc++.h>

using namespace std;
vector<int> houses;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int H, k; cin >> H;
    houses.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());
    cin >> k;
    int s = 1, e = 1e6+1;
    while (s + 1 < e) {
        int m = (s+e) / 2;
        //isnt it just simpler to use 2p?
        bool success = false;
        int used = 0;
        for (int i = 0; i < H; i++) {  //starts here
            used++;
            int next = i;
            if (m == 4500) {
            }
            while (next != H && houses[next] <= (houses[i] + 2 * m) % (int)1e6) {
                next++;
            }
            if (next == H) { success = true; break; }  //yays
            i = next-1;
            if (used == k) { break; }  //fail
        }
        if (success) {  //success
            e = m;
        }   else {
            s = m;
        }
    }
    cout << e << "\n";
}