#include <bits/stdc++.h>
#define vec vector
#define umap unordered_map
using namespace std;

vec<int> stick;
int total;
bool works(int len) {
    if (total % len != 0) { return false; }
    umap<int, int> hm;
    for (int x : stick) {
        hm[x]++;
    }
    for (int i = 0; i < total / len; i++) {
        vec<int> reach(len + 1, -1);
        reach[0] = 0;
        for (auto [x, f] : hm) {
            bool done = false;
            for (int k = 0; k < f; k++)
            for (int j = len - x; j > -1; j--) {
                if (reach[j + x] != -1 || reach[j] == -1) { continue; }
                reach[j + x] = x;
                if (j + x == len) { done = true; break; }
            }
            if (done) { break; }
        }
        if (reach[len] == -1) { return false; }
        int j = len;
        while (reach[j] != 0) {
            hm[reach[j]]--;
            cout << reach[j] << " ";
            if (hm[reach[j]] == 0) { hm.erase(reach[j]); }
            j -= reach[j];
        }
        cout << "\n";
    }
    return hm.empty();
}

void solve() {
    stick.clear();
    int N; cin >> N;
    stick.resize(N);  
    total = 0;
    for (int i = 0; i < N; i++) {
        cin >> stick[i];
        total += stick[i];
    }
    for (int i = *max_element(stick.begin(), stick.end()); i <= total; i++) {
        if (works(i)) { cout << i << "\n"; return; }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    int T; cin >> T; T = 1;
    auto beg = chrono::system_clock::now();
    double duration;
    while(T--) { solve(); }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - beg;
    // cout << elapsed.count() << "\n";
}