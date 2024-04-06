#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> heights(N);
    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];

    }
    //thsi looks like a direct 2 pointers problem...
    //the main idea is that if you have 2 pointers i and j, everything between them is also related to i and j.? no??
    //find a way to get the max of a subarray
    //if we can quickly grab the maximum of a subarray then... it should be easy to...?
    //ok so first
    //coordinate compress .?
//HOW DID I MISS THAT
}