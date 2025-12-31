#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i, a, b) for (auto i=a; i<(b); i++)

void solve() {
    int N, K; cin >> N >> K;
    vt<int> A(N);
    vt<int> f(N);
    rep(i, 0, N) cin >> A[i], A[i]--, f[A[i]]++;
    int sum = 0;
    int stop = 0;
    while (sum < K - 1) {
        sum += f[stop++];
    }
    deque<int> seq;
    rep(i, 0, N) {
        if (A[i] < stop) {
            seq.add(A[i]);
        }
    }

    //for each appearance of A[i] == stop - 1
    //it must be balanced across center to another
    //use a deque
    while (size(seq)) {
        if (seq.front() == seq.back()) {
            seq.pop_front();
            if (seq.size()) seq.pop_back();
        }   else if (seq.front() == stop - 1) {
            if (sum > K - 1) {
                sum--;
                seq.pop_front();
            }   else {
                cout << "NO" << "\n";
                return;
            }
        }   else if (seq.back() == stop - 1) {
            if (sum > K - 1) {
                sum--;
                seq.pop_back();
            }   else {
                cout << "NO" << "\n";
                return;
            }
        }   else {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) solve();
}