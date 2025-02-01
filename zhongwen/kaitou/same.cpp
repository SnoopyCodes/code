#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key
#define at find_by_order

using namespace __gnu_pbds;

template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    iset<array<int, 2>> is;
    vector<int> count(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        count[is.rat({x, i})]++;
        is.insert({x, i});
    }
    for (int i = 0; i < N; i++) {
        cout << count[i] << "\n";
    }
}