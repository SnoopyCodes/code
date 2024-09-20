#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> h;
bool cansee(int i, int stop, int j) {
    if (stop == 0) { return true; }
    //slp = h[stop] - h[i]) / (stop - i)
    //if slope of j >= slope of i then can see
    return ll(h[j] - h[i]) * (stop - i) >= ll(h[stop] - h[i]) * (j - i);
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //N^2 log whatever we want
    //first, we can do whatever we want to set everything up
    //it is easy to see whether each mountain can still see 
    //the mountain being updated; the problem is 
    //how do we decide the mountains themselves
    //lets first naively simulate it
    //or figure out a way to...

    //okay uh
    //mission accomplished
    //now we have to question about updates
    //how do we efficiently do updates?
    //lets say mountains can only get shorter.
    //basically lets say we have a matrix of slopes for every single
    //thing for every single one
    h.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<vector<int>> slp(N, vector<int>(N));
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            slp[i][j] = slp[i][j-1];
            bool res = cansee(i, slp[i][j], j);
            if (res) { slp[i][j] = j; cnt++; }
        }
    }
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int i, g; cin >> i >> g; i--;
        h[i] += g;
        //now what
    }
}