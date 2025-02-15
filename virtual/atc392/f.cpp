#include <bits/stdc++.h>
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key  //find how many less than element
#define at find_by_order //iterator to the kth element, [] essentially

//required in all policy ds
using namespace __gnu_pbds;


template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define long int64_t
const long INFL = 4e18;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //uhh
    //so.. 35 minutes left
    //use a rope

    int N; cin >> N;
    //think carefully
    //oh ur supposed to process it in reverse order
    //impl later just use rope
    //well shoot
    //implement this dang thing using some segtree i guess
    vec<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    iset<int> rem;
    for (int i = 0; i < N; i++) {
        rem.insert(i);
    }
    vec<int> ans(N);
    for (int i = N - 1; i > -1; i--) {
        int x = P[i]; x--;
        ans[*rem.at(x)] = i + 1;
        rem.erase(rem.at(x));
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}