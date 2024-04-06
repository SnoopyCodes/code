#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    vector<vector<int>> sss(K, vector<int>(N));
    //https://codeforces.com/problemset/problem/1931/F
    //iterate throuhg and check if they can be in a specific position
    //store the supposed position by iterating through the first 2
    //and check through the rest and thats it?
    //what if we make frequencies for each one
    //doesnt really work
    //or if we make frequencies ignoring the first element
    //so we know one is out of order and then for the rest
    //we should still construct the array though
    //problem: unknown where to insert
    //when first 2 are swapped next to each other
    //problem: unknown which array is correct when

    //its graph apparently
    //so lets make a graph of each pointing to the next one
    //oh its kinda like a linked list
    //so start off with the first one as expected
    //and then link each one to the next one
    //and then check through and only allow skipipng one link?
    //uhh in the graph we need to check if ???
    //ok so check in htis graph if there are no cycles? because if there are then 
    //wiat if there are cyccles why doesnt it work
    //so it hopefully always goes to the next one
    //but if it goes to one forward or backward then its' over?
    //maybe just make based on the last n-1
    //then if all of those work with the next one then we're fine

    // for (int i = 0; i < K; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cin >> sss[i][j];
    //     }
    // }
    // vector<int> real(N);
    // for (int i = 0; i < N; i++) {  //set for the ending N-1 and we fix the other later
    //     real[i] = sss[0][i];
    // }
    // if (K > 1) {
    //     //just search for our top element and insert it wherever it is found
    //     int find = real[0];
    //     for (int i = 0; i < N; i++) {
    //         if (sss[1][i] == find) { find = i; break; }  //missing element
    //     }
    //     int tmp = real[0];
    //     for (int i = 0; i < find; i++) {
    //         real[i] = real[i+1];
    //     }
    //     real[find] = tmp;
    // }
    // for (int i = 0; i < N; i++) {
    //     cout << real[i] << " ";
    // }
    // cout << "\n";
    // bool valid = true;
    // for (int i = 1; i < sss.size(); i++) {  //this is a valid check
    //     //iterate through the array and check if stuff is at most offset by one
    //     //ok lets graph
    //     int tmp = sss[i][0];
    //     //iterate through while theyre equal
    //     int j = 0, k = 0;
    //     j++;
    //     while (j < N && sss[i][j] == real[k]) {
    //         j++; k++;
    //     }
    //     if (real[k] != sss[i][0]) { valid = false; break; }
    //     k++;
    //     while (j < N && sss[i][j] == real[j]) {
    //         j++;
    //     }
    //     if (j != N) { valid = false; break; }
    // }
    // if (valid) { cout << "yes" << "\n"; }
    // else { cout << "no" << "\n";}
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}