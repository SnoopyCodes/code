#include <bits/stdc++.h>

using namespace std;
int throws;
vector<int> pos;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> throws;
    //we can throw a dice up to throws times
    //wait just precalculate
    //on any turn, every frequency is moved to the next 6
    pos.resize(max(7, throws + 1));
    pos[0] = 1;
    

}