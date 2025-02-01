#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    int max_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        max_sum += A[i];
    }
    //N <= 500
    //sum of A <= 1e5
    //500 * 1e5 somehow
    //wait we need to sum like
    //normally there are 3 options
    //put in one, put in two, or put in none
    //3^13 is an option
    //similar to the normal 2^n for knapsack
    //we can calculate reachable by one set
    //also calculate things to get somewhere
    //if there are 2 distinct paths to the same value then this is legal
    //therefore, I advocate iterating through VALUES, not items
    //store a list of choke points?
    //we want to be able to figure out when a thing works
    //do we check through paths every time?
    //
    for (int i = 0; i < N; i++) {
        
    }
}