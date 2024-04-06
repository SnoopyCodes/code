#include <bits/stdc++.h>

using namespace std;
struct Patch{
    int pos, taste, dist;
};
bool comp(Patch p1, Patch p2) {
    return p1.pos < p2.pos;
}
vector<pair<int, int>> patches;  //position, tastiness
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M,K;
    cin >> K >> M >> N;
    patches.resize(K+M+2);
    patches[0].first = -INFINITY;
    patches[0].second = -1;
    patches[M+K+1].first = INFINITY;
    patches[M+K+1].second = -1;
    for (int i = 1; i < K+1; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    for (int i = 1+K; i < K+M+1; i++) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }
    sort(patches.begin(), patches.end());
    int lnhoj = -1;
    for (int i = 0; i < K+M+2; i++) {

    }
}