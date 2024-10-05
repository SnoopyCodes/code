#include <bits/stdc++.h>

using namespace std;
vector<int> seg;
int SN;
void init(int N) {
    SN = N;
    seg.resize(2 * SN);
}
void alter(int p) {
    for (int i = (p + SN); i > 0; i /= 2) {
        seg[i]++;
    }
}
int query(int k) {
    //we want to find for each monster the minimum k for which it will fight?
    //if k increases, will we ever not fight one that we were fighting before?
    //YES YES WE DO
    int l = 0, r = k + 1;
    int res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> levels(N);  //in reality, this is # of level ups needed before we DONT fight
    for (int i = 0; i < N; i++) {
        cin >> levels[i];
    }
    init(N + 1);  //1-indexed?
    vector<int> prep(N);  //prep[i] = minimum value so that it will fight
    for (int i = 0; i < N; i++) {
        int s = 0, e = N;
        //find smallest that works?
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if ((long long) m * levels[i] > N) {
                e = m;
            }   else if (query(m) < m * levels[i]) { e = m; }
            else { s = m; }
        }
        prep[i] = e;
        alter(e);
    }
    for (int q = 0; q < Q; q++) {
        int i, x; cin >> i >> x; i--;
        cout << (x >= prep[i] ? "YES" : "NO") << "\n";
    }
}