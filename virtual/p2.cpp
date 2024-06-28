#include <bits/stdc++.h>

using namespace std;
vector<int> rooms;
void solve() {
    int N; cin >> N;
    rooms.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> rooms[i];
    }
    //we can iterate through 5 * 10^6 once at least
    //so fj wins 
    //then nhoj needs to force it to not get to 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}