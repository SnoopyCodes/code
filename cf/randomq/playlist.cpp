#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    /*
    each only has log(N) prime divisors. 
    we could lowkey just chunk them together sort of. 
    the big thing is: can we brute force it? i kinda don't really see why not.
    
    */
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}