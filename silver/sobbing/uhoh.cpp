#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //just like toposort or smth
    //any cereal that only has one like should be doned
    //put all the first choices first
    //this makes sense
    //and then for second choices
    //make the other one go first
    vector<set<int>> cereal(M); //for this cereal, this cow likes it
    vector<array<int, 2>> likes(N);
    for (int i = 0; i < N; i++) {
        int c1, c2; cin >> c1 >> c2; c1--; c2--;
        likes[i][0] = c1, likes[i][1] = c2;
        cereal[c1].insert(i);
        cereal[c2].insert(i);
    }
    

}