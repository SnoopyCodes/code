#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

void solve() {
    int X, Y, K; cin >> X >> Y >> K;
    //diagonals?
    int least = min(X, Y);
    cout << 0 << " " << 0 << " ";
    cout << least << " " << least << "\n";
    cout << 0 << " " << least << " ";
    cout << least << " " << 0 << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) {
        solve(); 
    }

}