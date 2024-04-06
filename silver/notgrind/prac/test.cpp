#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    set<int> s;
    s.insert(3);
    auto it = s.upper_bound(3);
    
    // Check if the iterator points to the end of the set
    if (it == s.end()) {
        cout << "Iterator points to end, no element greater than 3 found in the set." << endl;
    } else {
        cout << "Value found: " << *it << endl;
    }
}