#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> xors;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    xors.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> xors[i];
    }
    //it's possible to take like prefix xors
    //this much is known
    //basically find for each pair the xors between them
    //and multiply by the lengths
    //
}