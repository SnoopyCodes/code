#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    
    vector<int> chosen;
    vector<bool> used;
    chosen.resize(X);
    used.resize(X);
    for (int i = 0; i < X; i++) {
        int x; cin >> x; x--;
        chosen[i] = x;
    }
    int total = 0;  //# trits alr formed
    int del = 0; //# points at end
    //just check for 2 away as we form things
    sort(chosen.begin(), chosen.end());
    for (int i = 0; i < X; i++) {
        if (i+1 != X && chosen[i+1] - chosen[i] == 2) {  //good, do nothing
            total++;
            continue;
        }   else if (i+1 == X && chosen[i] - chosen[0] == N-2) {
            total++;
            break;
        }
        if (i+1 == X) { break; }
        //okay if not then we need to check for dist 2 away
        if (i + 2 != X && chosen[i+2] - chosen[i] == 2 && !used[i+1]) {  //sheesh
            used[i+2] = true;
            total++;
            //then delete i+1
            del++;
        }   else if (i + 2 == X && chosen[i] - chosen[0] == N - 2 && !used[i+1]) {
            del++;
            total++;
            used[i+1] = true;
        }
    }
    //total == deleted vertices
    //so then X - total - 2 is formed trits? doesnt sound right
    //wait this isnt how it works it needs to consider still the other things
    cout << total + X - del - 2 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}