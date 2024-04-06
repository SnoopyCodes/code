#include <bits/stdc++.h>

using namespace std;

struct Post {
    int x, y;
    bool putted;
    vector<Post> neighbors;
    int origin;
};
bool cmp(Post p1, Post p2) {
    return p1.x < p2.x;
}
bool boresort(Post p1, Post p2) {
    return p1.origin < p2.origin;
}
bool compx(Post p1, Post p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}
bool compy(Post p1, Post p2) {
    if (p1.y == p2.y) {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}
bool supersort(Post p1, Post p2) {
    return p1.neighbors.size() < p2.neighbors.size();
}
vector<Post> posts;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, P; cin >> N >> P;
    unordered_set<int> crying;
    crying.insert(1);
    crying.insert(2);
    cout << *crying.begin() << "\n";
    posts.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        posts[i].x = x, posts[i].y = y, posts[i].origin = i;
    }
    sort(posts.begin(), posts.end(), compx);
    for (int i = 0; i < N; i++) {
        int cur = posts[i].x;
        while (i < N && cur == posts[i+1].x) {
            // posts[i].neighbors.insert(posts[i+1]);
            // posts[i+1].neighbors.insert(posts[i]);
            i++;
        }
    }
    sort(posts.begin(), posts.end(), compy);
    for (int i = 0; i < N; i++) {
        int cur = posts[i].y;
        while (i < N && cur == posts[i+1].y) {
            // posts[i].neighbors.insert(posts[i+1]);
            // posts[i+1].neighbors.insert(posts[i]);
            i++;
        }
    }
    sort(posts.begin(), posts.end(), supersort);
    queue<Post> toposort;
    {
        int i = 0;
        while (posts[i].neighbors.size() == 2) {
            toposort.push(posts[i]);
            posts[i].putted = true;
        }
    }
    while (!toposort.empty()) {
        Post p = toposort.front();
        toposort.pop();
        //sobbing crying dying
        //remove p from all surrounding and connect to arr[]
        for (Post nf : p.neighbors) {
            if (nf.x == p.x) {
                // p.arr[0] = nf;
            }   else {
                // p.arr[1] = nf;
            }
            // nf.neighbors.erase(p);
            if (nf.neighbors.size() <= 2 && !nf.putted) { toposort.push(nf); }
        }
        //in theory this works
    }
    
    //okay we should be fine now
    //bro my unordered set doesnt work its joever
    //now find a  way to quickly query all the cows.
    //i guess we can double bs on which edge its on
    //very scuffed
    //wtf is this problem bro
    //okay double bs
    //then we know which one it begins and ends at
    //if we prefix sums one way through it and the other way throuhg it we can also find any distance required
    //and therefore select the smaller one in O(1) time
    //and finally we need only to mark on lengths of the graph which are covered..
    //ohh i get it its prefix sums afterwards i think
    //we dont need boresort rn only at the end
    //time complexity is hopefully like O(N log N)
}