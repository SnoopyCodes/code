#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int N, M; cin >> N >> M;
    //annoying casework
    //iterate from backwards and try to figure it out
    //everything affects.
    //we can assign the initial roles of everyone bar the last person.
    //we can also give tendencies to program.
    //so what happens is we find the first N people with tendencies to program or first M
    //oppositely then assign everyone else to program.
    //suppose we fill programming first. there are at least N people who want to program.
    //when we remove someone on this then there is always a replacement; that is,
    //find the first N + 1 people who want to program, and it is normal sum - replaced + (N + 1st pro).
    //the N + 1st programmer, though, might be the last person, if there are only N that want to.
    //what if someone not in programming is removed? we already have our N people for programming,
    //so everyone else is tester.
    //impl hell.
    long initial = 0;
    int ALL = N + M + 1;
    vt<ii<2>> j_bbers(ALL);
    vt<bool> type(ALL);
    int first_fill = -1;
    ii<2> sz { N, M };
    ii<2> ct { 0, 0 };
    for (int i = 0; i < ALL; i++) {
        cin >> j_bbers[i][0];
    }
    for (int i = 0; i < ALL; i++) {
        cin >> j_bbers[i][1];
    }
    
    for (int i = 0; i < ALL; i++) {
        type[i] = j_bbers[i][0] <= j_bbers[i][1];
        if (i < ALL - 1) {
            if (ct[type[i]] < sz[type[i]]) {
                ct[type[i]]++;
                if (ct[type[i]] == sz[type[i]] && first_fill == -1) {
                    first_fill = type[i];
                }
                initial += j_bbers[i][type[i]];
            }   else {
                ct[type[i] ^ 1]++;
                initial += j_bbers[i][type[i] ^ 1];
            }
        }
    }

    if (N == 0) { first_fill = 0; }
    else if (M == 0) { first_fill = 1; }

    if (first_fill) { //make "programmers" fill first.
        swap(N, M);
        for (int i = 0; i < ALL; i++) {
            swap(j_bbers[i][0], j_bbers[i][1]);
            type[i] = type[i] ^ 1;
        }
    }

    //find our N + 1st pro
    int pros = 0;
    int lst = 0;
    vt<bool> is_pro(ALL);
    for (int i = 0; i < ALL && pros < N + 1; i++) {
        is_pro[i] = !type[i];
        pros += is_pro[i] ||i == ALL - 1;
        if (pros == N + 1 && is_pro[i] || i == ALL - 1) {
            is_pro[i] = false;
            lst = i;
        }
    }

    //okay, then.
    for (int i = 0; i < ALL - 1; i++) {
        if (is_pro[i]) {
            cout << initial - j_bbers[i][0] + j_bbers[lst][0] - j_bbers[lst][1] + j_bbers[ALL - 1][1] << " ";
        }   else {
            cout << initial - j_bbers[i][1] + j_bbers[ALL - 1][1] << " ";
        }
    }
    cout << initial << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T;
    for (int tt = 1; tt <= T; tt++) { solve(); }
}