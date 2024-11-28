#include <bits/stdc++.h>

using namespace std;

//common file, required in all policy ds
#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key  //find how many less than element
#define at find_by_order //find the kth element, [] essentially

//required in all policy ds
using namespace __gnu_pbds;


template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> Q;
    iset<int> is;
    for (int q = 0; q < Q; q++) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'I') {
            is.insert(x);
        }   else if (c == 'D') {
            is.erase(x);
        }   else if (c == 'K') {
            int res = *is.at(x-1);
            if (is.at(x-1) == is.end()) { cout << "invalid" << "\n"; }
            else { cout << res << "\n"; }
        }   else {
            cout << is.rat(x) << "\n";
        }
    }
}