#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key
#define at find_by_order

using namespace __gnu_pbds;

template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define long int64_t

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("haircut.in", "r", stdin);
    // freopen("haircut.out", "w", stdout);
    int N; cin >> N;
    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }
    vector<long> diff(N + 1);
    //find out the contribution of each to the thing by sweeping left to right
    //meaning how many are greater than
    //each contribute to a diff array
    long ans = 0;
    iset<array<int, 2>> is;
    for (int i = 0; i < N; i++) {
        int amt = is.size() - is.rat({height[i], 100002});
        //these will be unleashed on height[i] + 1 to N
        diff[height[i] + 1] += amt;
        is.insert({height[i], i});
    }
    for (int i = 0; i < N; i++) {
        ans += diff[i];
        cout << ans << "\n";
    }
}