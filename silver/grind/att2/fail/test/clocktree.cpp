#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> shu;
vector<int> shi;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    shu.resize(N);
    shi.resize(N);
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        shi[i] = t;
    }
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        shu[a].push_back(b);
        shu[b].push_back(a);
    }
    //its a matter of entering each room only enough times to set each to 12
    //construct such a path
    //we need to find the "mod diffs" between each of the things
    //we can find for each room a path to every other room
    //does that help us though
    //it must be something about the modulo
    //we can start bessie anywhere
    //we should find for each one how many times we will need to walk over it in order to get all the others to 12
    //after all of that if it is 1 modulo 12 then we are good to go?
    //we should look at when it is impossible
    //if we just have 2 and they are of different modulos
    //this problem is likely the equivalent of being given strings of things that you can increase all by 1 at once
    //and then figuring out how they click together to make all of them modulo to 12
    //for each room we can make it 12 by switching back and forth with the neighbor
    //and then the neighbor can go to its neighbors
    //this is the equivalent of going back and forth 
    
}