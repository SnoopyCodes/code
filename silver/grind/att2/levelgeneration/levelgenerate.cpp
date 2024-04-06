#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {

    }
    //we can only have up to at most n-1 bridges
    //but we dont care about number of bridges we care about edges
    //if we create a dfs tree gg? i mean we can first start with our chain of n-1 things
    //and then consider connecting which ones?
    //clearly only adjacents
    //so 1 is allowed for only up to like 6
    //okay what next
    //afterwards then just binary search how much to add
}