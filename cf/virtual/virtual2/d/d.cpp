#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    v[N] = v[N-1];
    //see if we can remove stuff so it works
    //we should just consider what happens if we remove this number
    //basically, if it is still continuous if we remove a single number
    //if i-1 and i+1 works
    

    //we need to see where the problem is
    //we should just check each previous one and forward one
    //we can do that by ?
    vector<int> b(N);
    int cnt = 0;
    int last = 1;
    for (int i = 0; i < N - 1; i++) {
        b[i] = gcd(v[i], v[i+1]);
        if (b[i] < (i > 0 ? b[i-1] : 1)) { cnt++; }
    }
    b[N-1] = v[N-1];

    
    bool used = false;
    if (cnt == 0) { cout << "YES" << "\n"; return; }
    cout << cnt << "\n";
    //we check how many links around us are broken
    for (int i = 0; i < N; i++) {
        //we should first find the nonbroken ones around us
        int we = 0;
        if (i > 1 && b[i-1] >= b[i-2]) { we++; }
        if (i < N - 1 && b[i] <= b[i+1]) { we++; }
        int newb = gcd((i > 0 ? v[i-1] : v[i]), (i < N - 1 ? v[i+1] : v[i-1]));
        int fix = (i < N - 1 ? (b[i] > b[i+1]) : 0);
        cout << fix << "\n";
        if (i > 1 && newb >= b[i-2]) { fix++; }
        if (i < N - 1 && newb <= b[i+1]) { fix++; }
        cout << fix << " " << we << "\n";
        if (cnt == (fix - we)) {
            cout << i << "\n";
            cout << "YES" << "\n";
            used = true;
            return;
        }
    }
    cout << "NO" << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}