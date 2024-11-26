#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("balance.in", "r", stdin);
    //freopen("balance.out", "w", stdout);

    //it is trivial to find inversions
    //inversions, by definition, are amount of swaps between adj elements to sort it
    //so we can trivially obtain by subtraction an upper bound
    //thus the only problem is how many inversions we can skip by moving across the middle line
    //if left has more inversions, we want to move 1's into the left and flow 
    //the others the other way
    //if right has more inversions, we want to move 0's into the left and etc
    //when is this suboptimal?
    //im guessing this problem is symmetrical, so force left side to have more inversions
    //
    int N; cin >> N;
    //suppose that 

    //to calculate inversions for an index val 0: number of 1's before it
    //i feel like we flow stuff across until we can't

}