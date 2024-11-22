#include <bits/stdc++.h>

using namespace std;


#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key
#define at find_by_order
#define gset gp_hash_table
#define gmap gp_hash_table

using namespace __gnu_pbds;

template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N; cin >> N;
    vector<int> cow(N);
    for (int i = 0; i < N; i++) {
        cin >> cow[i]; cow[i]--;
    }
    int inc = N - 1;
    while (inc > 0 && cow[inc-1] < cow[inc]) { inc--; }
    //from this point upwards, it is basically already sorted, we just need to put it in the right order
    cout << inc << "\n";
    iset<int> sorted;
    for (int i = inc; i < N; i++) {
        sorted.insert(cow[i]);
    }
    for (int i = 0; i < inc; i++) {
        //how much to move this one?
        //first move it to inc
        int move = inc - i - 1;
        move += sorted.rat(cow[i]);
        cout << move << " \n"[i == inc - 1];
        sorted.insert(cow[i]);
    }

}