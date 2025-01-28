
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
    iset<int> s; s.insert(2); s.insert(2);
    cout << s.size() << "\n";
}