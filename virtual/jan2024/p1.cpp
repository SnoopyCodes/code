#include <bits/stdc++.h>

using namespace std;
vector<int> competence;
vector<array<int, 2>> memory;
set<int> mods;
vector<int> seg;
int N;
int query(int l, int r) {  //[)
    int mx = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { mx = max(mx, seg[l++]); }
        if (r & 1) { mx = max(mx, seg[--r]); }
    }
    return mx;
}
void solve() {
    int Q, C; cin >> N >> Q >> C;
    competence.resize(N);
    memory.resize(Q);
    mods.clear();
    seg.clear();
    for (int i = 0; i < N; i++) {
        cin >> competence[i];
        if (!competence[i]) { mods.insert(i); competence[i] = 1; }
    }
    for (int i = 0; i < Q; i++) {
        cin >> memory[i][0] >> memory[i][1];
        memory[i][0]; memory[i][1]--;
    }
    sort(memory.begin(), memory.end());
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        seg[i + N] = competence[i];
    }
    for (int i = N; i > 0; i--) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }

    int a = 0, h = 0;
    int lza = -1, amax = 0; //lz means last zero
    map<int, int> hmax;
    for (int q = 0; q < Q; q++) {
        while (a != memory[q][0]) {
            amax = max(competence[a], amax);
            if (q != 0) {
                hmax[competence[a]]--;
                if (!hmax[competence[a]]) { hmax.erase(competence[a]); }
            }
            if (mods.find(a) != mods.end()) { lza = a; }
            a++;
        }
        if (q == 0) {
            h = a;
        }
        if (memory[q][1] < h) { cout << -1 << "\n"; return; }  //h should never go back down
        while (h != memory[q][1]) {
            hmax[competence[h]]++;
            h++;
        }
        if (!hmax.empty() && (*hmax.rbegin()).first > amax) {
            if (lza == -1) {
                cout << -1 << "\n"; return;
            }
            amax = (*hmax.rbegin()).first;
            competence[lza] = amax;
            //should we leave lza?
            //we will not have to modify lza again i think is guaranteed
            lza = -1;
        }
        if (competence[h] <= amax && mods.find(h) == mods.end()) {
            cout << -1 << "\n"; return;
        }   else if (competence[h] <= amax) {
            competence[h] = amax + 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (competence[i] > C) { cout << -1 << "\n"; return; }
    }
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        seg[i + N] = competence[i];
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    //now we can run queries at will LMAO
    for (int q = 0; q < Q; q++) {
        int startbound = query(0, memory[q][0]);
        int mbound = query(memory[q][0], memory[q][1]);
        if (startbound < mbound || competence[memory[q][1]] <= startbound) {
            cout << -1 << "\n"; return;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << competence[i] << " \n"[i == N - 1];
    }
    //go to 
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T) { T--; solve(); }
}