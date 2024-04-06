#include <bits/stdc++.h>

using namespace std;
int LIM = 0;
struct Square {

};
const int M = -1;
const int O = -2;
vector<vector<int>> grid;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //as bessie moves through the maze, she is not allowed to make the same move twice
    //but she has 2 options: making M or making O
    //oh wait she has to collect them
    //fine then just go throuhg the maze, check everything, and figure out all the ways to collect them
    //you may not step on a tile more thna 2 * N times lets say
    //we can use bitsets of size 10 to simulate grids
    //we can connect squares that can connect to each other without actually needing to pass through something 
    //how do we do that?
    //anyways how do we use a set to simulate our thing?
    //just say position i, j and this is the state of our board
    //not too hard right?
    //then we just iterate through all our boards and check
    //but we need the set to cooperate
    //we can also just use an integer to simulate it?
    //each move requires a check
    //we can use...
    //a 3 dimentional piece of crap
    //of course we do
    int N; cin >> N;
    LIM = 2 * N;
}