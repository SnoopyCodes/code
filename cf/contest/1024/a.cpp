#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M, P, Q; cin >> N >> M >> P >> Q;
    //p <= n
    //set up n % p at the end
    int cur = N / P * Q;
    int rem = N % P;
    int need = M - cur;
    if (rem == 0 && need != 0) { cout << "NO" << "\n"; }
    else if (need == 0 && rem == 0) { cout << "YES" << "\n"; }
    else {
        //if the part of some of an array > |P| then idt we can do it?
        //like we need 8 in the last 2 but P gives only 4 can we do it? yes?
        cout << "YES" << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}