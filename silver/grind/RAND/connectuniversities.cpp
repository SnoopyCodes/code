#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> towns;
vector<bool> is_univ;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, k; cin >> n >> k;
    //????
    //MOST COMPREHENSIBLE CODEFORCES QUESTION OH MY DAYS
    towns.resize(n);
    is_univ.resize(n);
    for (int i = 0; i < 2 * k; i++) {
        int x; cin >> x;
        is_univ[x-1] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
    }
    //now what?
    //so let's say we are at a node
    //we know there are dists of 3 and 5 away, and behind us there is one more
    //i dont think it actually matters 
    //1 2 4 6
    //1 3 4 6
    //5 + 1 or 2 + 2
    //oh
    //5 + 2 or 3 + 4
    //same thing
    //if we consider every node in terms of distance from root
    //wait bro this is so sad like
    //we have to consider all the different subtrees
    //i think the optimal strategy is to dfs guys
    //if it were on a number line
    //we need to choose hte furthest distances at every endpoint
    //how how how how how how hwo hwo how how  how ghow how how how how
    //
}