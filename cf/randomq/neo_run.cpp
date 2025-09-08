#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;
#define add push_back

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    map<int, vt<int>> occ;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        occ[A[i]].add(i);
    }

    //connect stuff together
    //make counts
    //map<int, vt<int>> hell yeah
    //so manually go through the top one.
    //wait im bad you have to check borders.
    set<int> pressed;
    int ct = 0;
    for (auto it = occ.rbegin(); it != occ.rend(); ++it) {
        auto cur = (*it).second;
        for (int j = 0; j < size(cur); j++) {
            int i = j + 1;
            while (i < size(cur) && cur[i] - cur[j] == i - j) {
                i++;
            }
            if (!pressed.count(cur[j] - 1) && (!pressed.count(cur[i - 1] + 1))) { ct++; }
            for (int k = j; k < i; k++) {
                pressed.insert(cur[k]);
            }
            j = i - 1;
        }
    }
    cout << ct << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}