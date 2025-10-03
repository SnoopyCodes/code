#include <bits/stdc++.h>

using namespace std;

#define long long long
/*
you are given a general graph
find for each vertex w
the number of node pairs (u, v)
for which a simple path from u to v must necessarily cross w
*/


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
/*
O(N) solution:
transform it into a block cut tree
for any non articulation points
the answer is 0
for articulation points the answer is
subtree size of all nodes rooted from there
*/