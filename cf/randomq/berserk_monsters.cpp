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

void solve() {
    int N; cin >> N;
    vt<int> A(N), D(N);
    for (int &u : A) { cin >> u; }
    for (int &u : D) { cin >> u; }

    //just store stuff in sets
    set<int> alive;
    for (int i = 0; i < N; i++) {
        alive.insert(i);
    }
    vector<int> will_die;
    vt<bool> dead(N);
    for (int i = 0; i < N; i++) {
        int dmg = 0;
        if (i > 0) { dmg += A[i - 1]; }
        if (i < N - 1) { dmg += A[i + 1]; }
        if (dmg > D[i]) {
            will_die.add(i);
            dead[i] = true;
        }
    }
    for (int i = 0; i < N; i++) {
        set<int> next;
        cout << will_die.size() << " \n"[i == N - 1];
        for (int j : will_die) {
            auto it = alive.find(j);
            if (it != alive.begin()) {
                int k = *--it;
                if (!dead[k]) { next.insert(k); }
                ++it;
            }
            if (it != --alive.end()) {
                int k = *++it;
                if (!dead[k]) { next.insert(k); }
                --it;
            }
            alive.erase(j);
        }
        will_die.clear();
        for (int j : next) {
            auto it = alive.find(j);
            int dmg = 0;
            if (it != alive.begin()) {
                dmg += A[*--it];
                it++;
            }
            if (it != --alive.end()) {
                dmg += A[*++it];
                it--;
            }
            if (dmg > D[j]) {
                will_die.add(j);
                dead[j] = true;
            }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}