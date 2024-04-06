#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> brands;
vector<bool> satisfy;  //whether a cow has got a cereal or not
vector<pair<int, int>> cows;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int M; cin >> M;
    brands.resize(M);
    satisfy.resize(N);
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
        brands[cows[i].first].push_back(i);
        brands[cows[i].second].push_back(i);
    }
    //
    //observe: some brands are more popular than others
    //our graph will be made up of vertices brands with edges to intermediary cows which redirect
    //to the other brand they enjoy [and therefore cows are edges
    //first solve it WITHOUT priority.
    //simply find duplicates?
}