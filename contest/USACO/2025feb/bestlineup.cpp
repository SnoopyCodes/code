#include <bits/stdc++.h>

#define vec vector
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using namespace std;

void solve() {
    int N; cin >> N;
    vec<int> A(N);
    vec<vec<int>> appear(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
        appear[A[i]].push_back(i);
    }
    //try to maximize its appearance
    int l = -1;  //we can concatenate after l without consequence
    vec<int> seq;
    bool done = false;
    rep(i, -N) {
        rep(j, appear[i].size()) {
            if (appear[i][j] > l) {
                l = appear[i][j];
                seq.push_back(appear[i][j]);
            }   else if (!done) {
                //operation time
                //5 4 3 4 2 1
                //this case will not happen
                //4 3 2 1 3
                //4 3 3 and we need to move 2
                //we can only move the LAST OCCURRENCE
                //so check if the second to last occurrence is greater than us
                //if it is, we dip
                if (seq.size() < 2 || seq[seq.size() - 2] < appear[i][j]) {
                    done = true;
                    seq.push_back(appear[i][j]);
                    l = appear[i][j];
                }
            }
        }
    }
    rep(i, seq.size()) {
        cout << A[seq[i]]+1 << " \n"[i == seq.size() - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}