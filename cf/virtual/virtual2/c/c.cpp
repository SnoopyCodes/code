#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector<int> found(N);
    for (int i = 0; i < N; i++) {
        cin >> found[i];
    }
    //find the differences
    //we need to first check if such an element exists in the end
    int M; cin >> M;
    vector<int> mods(M);
    for (int i = 0; i < M; i++) {
        cin >> mods[i];
    }
    bool yay = false;
    for (int i = 0; i < N; i++) {
        if (found[i] == mods[M-1]) { yay = true; break; }
    }
    if (!yay) { cout << "NO" << "\n"; return; }
    //now search for differences between a and b
    multiset<int> s;
    for (int i = 0; i < N; i++) {
        if (v[i] != found[i]) {
            s.insert(found[i]);
        }
    }
    if (s.size() > M) { cout << "NO" << "\n"; return; }
    for (int i = 0; i < M; i++) {
        if (s.find(mods[i]) != s.end()) {
            s.erase(s.find(mods[i]));
        }
    }
    if (s.empty()) { cout << "YES" << "\n"; }
    else {cout << "NO" << "\n";}
    //do we just assemble a multiset of our own
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}