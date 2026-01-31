#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    int M = N;
    vt<int> val, amt;
    int lst = -1, num = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        if (lst != x) {
            if (lst != -1) {
                val.add(lst);
                amt.add(num > 1);
            }
            lst = x;
            num = 1;
        }   else {
            num++;
        }
    }
    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }
    val.add(lst);
    amt.add(num > 1);

    N = size(val);

    int twogroups = accumulate(begin(amt), end(amt), 0);
    
    int last = -1, lasti = -1;
    int sub = 0;
    for (int i = 0; i < N; i++) {
        int v = val[i];
        if (amt[i]) {
            if (v == last) {
                int since = 0;

                for (int j = lasti + 1; j < i; j++) {
                    if (val[j] == v) {
                        since = 0;
                    }   else {
                        since++;
                        if (since > 1) {
                            break;
                        }
                    }
                }

                if (since < 2) {
                    sub++;
                }
            }
            last = v;
            lasti = i;
        }
    }
    
    cout << N + twogroups - sub << "\n";
}
/*
theres something im not considering
so i am saying
if anything has frequency > 2 then i dont care
if anything  has frequency 1 i will never move it
oh it could be optimal to move it though...
we only move it if we need it as a buffer between two occurrences of v
a single element can move unless the element before and after it are the same
if they're 2 on either side then we can move

*only one element in a chain of 1s needs to move*
but for like 221211222
our heroes may be totally immobilized
i think that is  pretty much the constraint though?
if both sides are the same then cant move
otherwise can move for any element other than ourselves.

store these occurrences inside a set?
i think the dp structure is such that
there are only a few values worth keeping at a time
probably like 2
we either choose to put in
or not put in
putin
axya
aaxayaa
wait is axa the only way where we cant add a to bottom?
not quite
so isnt it just # of 2 groups where consecutive as are separated by more than 1?
just count those

*/