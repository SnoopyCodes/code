#include <bits/stdc++.h>
using namespace std;

//common file, required in all policy ds

//rat- how many less than element
//at- iterator to kth element
//__gnu_pds- required probably
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define rat order_of_key  //find how many less than element
#define at find_by_order //iterator to the kth element, [] essentially

template <class T>
using iset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class K, class V>
using imap = tree<K, V, std::less<K>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
using imset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//use s.erase(s.upper_bound(value)) to remove one occurrence

template<typename T> using gset = gp_hash_table<T, null_type>;
template<typename K, typename V> using gmap = gp_hash_table<K, V>;

gmap<int, int> table;
gset<int> hash_set;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> sals(N);
    iset<array<int, 2>> s;
    for (int i = 0; i < N; i++) {
        cin >> sals[i];
        s.insert({sals[i], i});
    }

    for (int q = 0; q < Q; q++) {
        char t; cin >> t;
        if (t == '!') {
            int k, x; cin >> k >> x; k--;
            s.erase({sals[k], k});
            sals[k] = x;
            s.insert({sals[k], k});
        }   else {
            int l, r; cin >> l >> r;
            cout << s.rat({r, (int)1e9}) - s.rat({l, 0}) << "\n";
        }
    }
}