#include <bits/stdc++.h>

using namespace std;
vector<int> cows;
vector<int> maxes;
vector<pair<int, int>> mem;
map<int, int> edit;
map<int, int> edited;  //stores index, value edited
int getMax(int index) {
    int init = maxes[index];
    if (edited.size() != 0) {
        int propose = (*(--edited.upper_bound(index))).first;
        //check if propose is valid
        propose = propose <= index ? cows[propose] : -1;
        init = max(init, propose);
    }
    return init;
}
int nextEdit(int index) {
    int x = (*(--edit.upper_bound(index))).first;
    return x <= index ? x : -1;
}
void solve() {
    int N, Q, C; cin >> N >> Q >> C;
    cows.clear(); mem.clear(); maxes.clear(); edit.clear(); edited.clear();
    cows.resize(N);
    maxes.resize(N);
    mem.resize(Q);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        if (cows[i] == 0) { cows[i] = 1; edit[i] = 1; }
        if (i == 0) { maxes[i] = cows[i]; }
        else { maxes[i] = max(maxes[i-1], cows[i]); }
    }
    for (int i = 0; i < Q; i++) {
        cin >> mem[i].first >> mem[i].second;
        mem[i].first--; mem[i].second--;
    }
    sort(mem.begin(), mem.end());
    bool valid = true;
    for (int i = 0; i < Q; i++) {
        int fmax = getMax(mem[i].first);
        int smax = getMax(mem[i].second-1);
        int nedit = nextEdit(mem[i].first);
        if (fmax < smax && nedit != -1) {
            cows[nedit] = smax;
            edited[nedit] = smax;
            if (edited.size() > 1 && (*(--edited.upper_bound(nedit))).second > edited[nedit]) {
                edited[nedit] = (*(--edited.upper_bound(nedit))).second;
            }
        }   else if (fmax < smax) {
            valid = false; break;
        }
        if (nextEdit(mem[i].second) == mem[i].second) {
            if (cows[mem[i].second] <= getMax(mem[i].second-1)) {  //set
                int ind = mem[i].second;
                cows[mem[i].second] = getMax(mem[i].second-1)+1;
                edited[ind] = getMax(mem[i].second-1)+1;
                if (edited.size() > 0 && (*(--edited.upper_bound(ind))).second > edited[ind]) {
                    cows[ind] = (*(--edited.upper_bound(ind))).second;
                    edited[ind] = (*(--edited.upper_bound(ind))).second;
                }
            }
        }   else {
            if (cows[mem[i].second] <= getMax(mem[i].second-1)) {
                valid = false; break;
            }
        }
    }
    if (valid) {
        for (int i = 0; i < N; i++) {
            if (cows[i] > C) { valid = false; break; }
            if (cows[i] == 0) { cows[i] = 1; }
        }
        for (int i = 0; i < Q; i++) {
            int a = mem[i].first, b = mem[i].second;
            if (getMax(a) < getMax(b-1)) { valid = false; break; }
            if (getMax(a) >= getMax(b)) { valid = false; break; }
        }
    }
    if (valid) {
        for (int i = 0; i < N; i++) {
            cout << cows[i];
            if (i < N-1) { cout << " "; }
        }
    }   else {
        cout << -1;
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}