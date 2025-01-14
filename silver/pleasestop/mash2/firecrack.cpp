#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M, A, B; cin >> N >> M >> A >> B;
    int pold = abs(A - B);
    int rund = A < B ? A - 1 : N - A;  //dist from endpoints
    //wait no he launch immediately and run
    //is there any case where he runs and then launches later
    //idts he just launches immediately LOOOOL
    vector<int> fire(M);
    for (int i = 0; i < M; i++) {
        cin >> fire[i];
    }
    sort(fire.begin(), fire.end());
    int s = 0, e = M + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        //simulate process between each one
        //first, he launches all of them
        //if pold is > 
        if (pold <= m) { e = m; continue; }
        int curd = pold - m;
        bool valid = true;
        int t = 0;
        for (int i = m - 1; i > -1; i--) {  //launch right after another
            int tr = pold + rund - t;
            if (tr <= fire[i]) { valid = false; }
            t++;
        }
        if (valid) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) { solve(); }
}