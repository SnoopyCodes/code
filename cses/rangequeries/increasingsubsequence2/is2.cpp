#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    //we can try to figure out for each element how many start/end there
    //the number of sequences that end on this one are like
    //the ones that are less than it, and itself
    //basically, upon coming across a new element
    //we need to query for summing the answers of all elements
    //lower than itself
    //then update our index to our contribution
    //we can do this by coord compressing stuff
    //then query
    //okay i will have to do this tomorrow
}