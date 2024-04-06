#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> cows;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("sabotage.in", "r", stdin);
    // freopen("sabotage.out", "w", stdout);
    int N; cin >> N; cows.resize(N);
    for (int i = 0; i < N; i++) { cin >> cows[i]; }
    //2p, or kadaes
    //can we just use 2 pointers it might be less painful
    //but kadanes is definitely correct so
    
    //KADANES lol
    //does that help thoguh
    //as we go through the array save the smallest average in the range from 1 to the index...
    //i dont know if that works
    //it should actually
    //we should also judge against removing all of it but idk how to do that
}