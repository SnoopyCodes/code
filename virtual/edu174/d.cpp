#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=(s);x!=(e);(s)<(e)?x++:x--)
#define rep2(x,e) rep3(x,e>0?0:-e-1,e>0?e:-1)

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int solve(string s) {
    int N = s.size();
    vec<int> A(N);
    rep(i, N) {
        A[i] = s[i] - 97;
    }
    //okay lets go
    //we want to find the minimum length substring such that
    //all outside perform i to N - i - 1 "matches"
    //lets take the case where we don't cross center (frequencies on either side are equal)
    //find the largest suffix and prefix where they match, very simple
    //ok, then what about crossing?
    //if we cross, we want overall suffix and prefix to be the same?
    //why is this incorrect?
    vec<int> freq(26);
    rep(i, N) {
        freq[A[i]]++;
    }
    vec<int> half(26);
    rep(i, N / 2) {
        half[A[i]]++;
    }
    bool dontcross = true;
    rep(i, 26) {
        half[i] -= freq[i] / 2;
        if (half[i] != 0) { dontcross = false; }
    }
    //cross is probably correct
    //chat i couldve stress tested this
    if (dontcross) {
        int m = N / 2;
        int pf = N, sf = 0;
        rep(i, m) {
            if (A[i] != A[N - i - 1]) {
                pf = i;
                break;
            }
        }
        rep(i, -m) {
            if (A[i] != A[N - i - 1]) {
                sf = i;
                break;
            }
        }
        if (pf > sf) { return 0; }
        return sf - pf + 1;
    }   else {
        int pf = N;
        rep(i, N / 2) {
            if (A[i] != A[N - i - 1]) {
                pf = i;
                break;
            }
        }
        int sf;
        rep(i, N / 2, N) {
            half[A[i]]++;
            bool ok = true;
            rep(i, 26) {
                if (half[i] < 0) { ok = false; }
            }
            if (ok) { sf = i; break; }
        }
        return sf - pf + 1;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) {
        string s; cin >> s;
        int res = solve(s);
        reverse(s.begin(), s.end());
        cout << min(res, solve(s)) << "\n";
    }
}