#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //it is known that within the window, making all elements equal happens
    //at the median
    //we can use priority queues to maintain this i think
    //probably sets actually
    //
    int N, K; cin >> N >> K;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    set<int> lower;  //keeps the lower half
    set<int> upper; //upper half
    for (int i = 0; i < K; i++) {

    }
    
}