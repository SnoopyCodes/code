#include <bits/stdc++.h>

using namespace std;
struct Post {  //this is a point, but well i dont want to type
    int x, y, i;
    int u = -1, d = -1, r = -1, l = -1;
};
bool compi(Post p1, Post p2) {
    return p1.i < p2.i;
}
bool same(Post p1, Post p2) {
    return p1.x == p2.x && p1.y == p2.y;
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
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("lasers.in", "r", stdin);
    //freopen("lasers.out", "w", stdout);
    int N; cin >> N;
    Post s, e; cin >> s.x >> s.y >> e.x >> e.y;
    s.i = N, e.i = N + 1;
    vector<Post> posts(N);
    for (int i = 0; i < N; i++) {
        cin >> posts[i].x >> posts[i].y;
        posts[i].i = i;
    }
    posts.push_back(s); posts.push_back(e);
    sort(posts.begin(), posts.end(), compx);
    for (int i = 0; i < N; i++) {
        int beg = i;
        while (i < posts.size() && posts[i].x == posts[beg].x) {
            if (i != beg) {
                posts[i].d = posts[i-1].i;
            }
            if (i + 1 < posts.size() && posts[i+1].x == posts[beg].x) {
                posts[i].u = posts[i+1].i;
            }
            i++;
        }
        i--;
    }
    sort(posts.begin(), posts.end(), compy);
    for (int i = 0; i < N; i++) {
        int beg = i;
        while (i < posts.size() && posts[i].y == posts[beg].y) {
            if (i != beg) {
                posts[i].l = posts[i-1].i;
            }
            if (i + 1 < posts.size() && posts[i+1].y == posts[beg].y) {
                posts[i].r = posts[i+1].i;
            }
            i++;
        }
        i--;
    }
    sort(posts.begin(), posts.end(), compi);
    //okay it is time to run bfs
    vector<int> visited(posts.size(), -1);
    deque<array<int, 2>> q; q.push_front({N, -1});
    //we need a dir somehow
    //uhhh
    //so uh
    //we should only ever use something once
    //we should add like idk 
    bool h = false, v = true;
    visited[N] = 0;
    while (!q.empty()) {
        auto x = q.front();
        Post p = posts[x[0]];
        q.pop_front();
        if (p.d != -1 && x[1] != u) {
            visited[p.d] = visited[p.i]+1;
            q.push({p.d, d});
        }
        if (p.l != -1 && x[1] != l) {
            visited[p.l] = visited[p.i]+1;
            q.push({p.l, l});
        }
        if (p.r != -1 && visited[p.r] == -1) {
            visited[p.r] = visited[p.i]+1;
            q.push({p.r, r});
        }
        if (p.u != -1 && visited[p.u] == -1) {
            visited[p.u] = visited[p.i]+1;
            q.push({p.u, u});
        }
    }
    for (int i = 0; i <= N + 1; i++) {
        cout << visited[i] << "\n";
    }
    cout << visited[N+1] - 2 << "\n";
    //later broadcasts should still be put in
}