#include <bits/stdc++.h>

using namespace std;
vector<int> col;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int Q; cin >> Q;
    col.resize(n);
    for (int i = 0; i < n; i++) {
        col[i] = s[i] - 'a';
    }
    //find the longest continuation for both of them
    //or we can find the distances for each of them
    //from the next set
    //store for each index the lowest and highest that the group goes
    //we can like O(n^2) this lolz
    //anyways
    //but we need to answer each one in like O(1)
    //which isn't hard just store for each color the length and max koyomity of that length
    //wait what its not dp im so done
    for (int q = 0; q < Q; q++) {
        int m, c;
        cin >> m >> c;
        c -= 'a';
    }
}