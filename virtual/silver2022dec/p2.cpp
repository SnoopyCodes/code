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
    //run sieve
    //so sieve
    //isnt this basically dp?
    //okay help the other thing idk what it is
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}