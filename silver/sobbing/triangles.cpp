#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<array<int, 2>> posts;
bool comp(array<int,2> a1, array<int, 2> a2) {
    if (a1[1] == a2[1]) { return a1[0] < a2[0]; }
    return a1[1] < a2[1];
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("triangles.in", "r", stdin);
    //freopen("triangles.out", "w", stdout);
    int N; cin >> N;
    posts.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> posts[i][0] >> posts[i][1];
    }
    //i really hope this is doable wtf
    //we want all that he can form lol
    //oh we only form one triangle :blobpat:
    //N choose 3 is unfunny
    //how do we move from one x-value to another x-value?
    //when we do a transition 
    //we say we want to use the height along this x-value
    //can we iterate through all points in this thing
    //i think we need to compute prefix sums for every y-value ngl
    //i wont even bother coord compressing just use a map xd
    //wait do it for both i think
    //uhhh
    //okay this is doable with binary search and stuff i just really hate it
    //because we need to do like double thing
    sort(posts.begin(), posts.end(), comp);
    map<int, vector<ll>> ypfx;
    /* pfx ys*/ {
        int i = 0, j = 1;
        while (i < N) {
            
            while (j < N && posts[j][1] == posts[i][1]) {
                
                j++;
            }
            i = j;
        }
    }

}