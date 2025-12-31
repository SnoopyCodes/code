#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for (auto i=a; i<(b);i++)
void solve() {
    int N; cin >> N;
    long K; cin >> K;
    if (N < 63 && 1LL << N - 1 < K) {
        cout << -1 << "\n";
        return;
    }
    int M = N - 1;
    queue<int> front;
    stack<int> back;
    rep(i, 1, N) {
        M--;
        if (M >= 63 || M < 63 && 1LL << M >= K) {
            front.push(i);
        }   else {
            back.push(i);
            K -= 1LL << M;
        }
    }
    front.push(N);


    while (front.size()) {
        cout << front.front() << " ";
        front.pop();
    }
    
    while (back.size()) {
        cout << back.top() << " ";
        back.pop();
    }
    cout << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}