#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
vector<pair<ll, ll>> posts;
vector<pair<ll, ll>> sums;
bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.x == p2.x) { return p1.y < p2.y; }
    return p1.x < p2.x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("triangles.in", "r", stdin);
    // freopen("triangles.out", "w", stdout);
    int N; cin >> N;
    posts.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> posts[i].x >> posts[i].y;
    }
    //lets go
    //implmenet
    //so we sort by x values first
    //and then for all of those x values
    //compute the y-value sums for all of the points
    sort(posts.begin(), posts.end());
    for (int i = 0; i < N; i++) {
        //now find the sum of all the y's on the same x
        //first sum up all the distances for the first one
        //and then to move to the next one
        //
    }
}