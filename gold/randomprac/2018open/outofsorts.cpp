#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>  //common file?

#define rat order_of_key  //find how many less than element
#define at find_by_order //find the kth element, [] essentially

using namespace __gnu_pbds;

template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout);
    int N; cin >> N;
    //conducts stable sorting
    set<array<int, 2>> sorter;
    vector<int> end(N);
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sorter.insert({A[i], i});
    }
    int cnt = 0;
    for (auto x : sorter) {
        A[x[1]] = cnt;  //exact ordering!
        end[x[1]] = cnt++;
    }
    //A[i] now has distinct elements, end has inverse permutation
    //for anything in sorted order already we need not sweep at all
    //how do we tell if something will become sorted without our sweeping?
    //i have no idea
    //

}