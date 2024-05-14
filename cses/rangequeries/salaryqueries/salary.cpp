#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    vector<int> original(N);
    oset<array<int, 2>> o;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        o.insert({k, i});
        original[i] = k;
    }
    for (int q = 0; q < Q; q++) {
        string s; cin >> s;
        if (s[0] == '?') {
            int a, b; cin >> a >> b;
            cout << o.order_of_key({b, INT_MAX}) - o.order_of_key({a-1, INT_MAX}) << "\n";
        }   else {
            int i; cin >> i; i--;
            //original[k] is val
            o.erase({original[i], i});
            int k; cin >> k; k;
            original[i] = k;
            o.insert({k, i});
        }
    }
    
}