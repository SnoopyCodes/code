#include <bits/stdc++.h>

using namespace std;
vector<int> salaries;
//i give up just look at iframe iframe orz
vector<array<int, 2>> help;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    salaries.resize(N);
    help.reserve(N + Q);
    //so we can get possible salaries of everyone
    //store queries
    //how does coord compression work?
    //what do we need for the segtree, first of all?
    //like, everything basically
    //all the possible things
    //we will do a true coord compression
    //because i like suffering
    //but in usaco maps for coord compression is smart
    vector<array<int, 3>> qs;
    for (int i = 0; i < N; i++) {
        cin >> salaries[i];
        help.push_back({salaries[i], i});
    }
    for (int i = 0; i < Q; i++) {
        char c; cin >> c;
        qs[i][0] = c == '!';  //updates
        if (qs[i][0]) {
            int k, x; cin >> k >> x;
            qs[i][1] = k-1;
            qs[i][2] = x;
            help.push_back({x, INT_MAX});
        }   else {
            //how do we compress these? questions i forgot to answer
            //bruh
            int a, b; cin >> a >> b;
            qs[i][1] = a, qs[i][2] = b;
        }
    }
    //coord compress now
    //queries is finished, but idk how to coord compress
    sort(help.begin(), help.end());
    vector<int> fake;  //i need to initialize better
    fake.reserve(N);
    for (int i = 0, rl = 0; i < N + Q; i++, rl++) {
        fake.push_back(help[i][0]);  //push actual value
        if (help[i][1] != INT_MAX) {
            fake[rl]++;
            salaries[help[i][1]] = rl;
        }
        while (i + 1 < N + Q && help[i][0] == help[i+1][0] && help[i+1][1] != INT_MAX) {
            i++;
            fake[rl]++;
            salaries[help[i][1]] = rl;
        }
        while (i + 1 < N + Q && help[i][0] == help[i+1][0]) { i++; }
    }
    int segn = fake.size();
    vector<int> seg(segn);
    for (int i = 0; i < segn; i++) {
        seg[i + segn] = fake[i];
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
    for (int q = 0; q < Q; q++) {
        if (qs[q][0]) {  //is update

        }
    }

}