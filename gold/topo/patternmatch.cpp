#include <bits/stdc++.h>

using namespace std;
struct node {
    string s;
    int i;
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //hopefully is fun
    //this looks really fun actually i like it
    int N, M, K; cin >> N >> M >> K;
    vector<node> P(N);  //patterns
    vector<node> S(N); //match
    for (int i = 0; i < N; i++) {
        cin >> P[i].s;
        P[i].i = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> S[i].s >> S[i].i; S[i].i--;
    }
    //we can figure out if a string matches another
    //n1 fits in n2
    auto match = [&](const node& n1, const node& n2) {
        for (int i = 0; i < K; i++) {
            if (n2.s[i] == '_' || n1.s[i] == n2.s[i]) { continue; }
            return false;
        }
        return true;
    };

    //NM is defintiely too slow
    //leave order of patterns unchanged
    //.
    //pass stuff to 
}