#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> del;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        del.clear();
        multiset<int> ms;
        
        for (int i = 0; i < N; i++) {
            int element;
            cin >> element;
            ms.insert(element);
        }
        
    }
}