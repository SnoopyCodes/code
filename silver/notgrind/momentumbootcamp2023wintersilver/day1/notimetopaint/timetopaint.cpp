#include <bits/stdc++.h>

using namespace std;
vector<int> fence;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    for (int i = 0; i < N; i++) { fence[i] = s[i] - 'A'; }
    for (int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b;
        a--; b--;
        //we can first look at the entire fence and then
        //first claculate the whole thing
        //find all the strokes
        //any strokes that are wholly encompassed in the query we can now ignore
        //otherwise i think we still include them
        //yea and then we just move from 0 to n
        //so usaco idea is we save at each location how many there are which is good idea
        //question is why these aren't the same
    }
}