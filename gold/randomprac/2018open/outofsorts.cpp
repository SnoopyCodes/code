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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N; cin >> N;
    //conducts stable sorting
    //take the entire array: what is to be noticed is that bubble corrects one left imbalance
    //and right imbalance
    //wait ok incredible use iset
    vector<array<int, 2>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i][0]; A[i][1] = i;
    }
    sort(A.begin(), A.end());
    iset<int> is;
    int ans = 1;
    //insert each element

    for (int i = 0; i < N - 1; i++) {
        is.insert(A[i][1]);
        ans = max(ans, i - (int) is.rat(i + 1) + 1);
    }
    cout << ans << "\n";

    //now what
    //

}