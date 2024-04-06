#include <bits/stdc++.h>
#define ll long long

using namespace std;
int pasture[500][500];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pasture[i][j];
        }
    }
    int i = 0, j = 0;  //2 pointers?
    vector<int> wx;
    vector<int> nx;
    vector<int> wy;
    vector<int> ny;
    bool has100 = false;
    while (i != N) {  //count the number of viables are in here?
    //row by row, what can we include?
        
    }
    //uhh make a list of the largest viable intervals where no intervals encompass each other
    //for both x and y
    //how would we find all viable intervals?
    //we have 3 portions: with 100 (both), with 100 (only x), with 100 (only y)
    //count with 2p all portions where the intervals > 100
    //then calculate
    //...
}