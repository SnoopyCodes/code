#include <bits/stdc++.h>
#define long int64_t
using namespace std;

//see if our loop is correct or not

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int C, N; cin >> C >> N;
    //first deal with forming the convex hull
    vector<array<int, 3>> xp;
    vector<array<int, 3>> yp;
    vector<array<int, 2>> mp(N);  //each fence post is at what pos
    vector<long> to(N);
    vector<int> pos(N);  //position of fence post in each of them
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        xp.push_back({x, y, i});
        yp.push_back({y, x, i});
    }
    sort(xp.begin(), xp.end());
    sort(yp.begin(), yp.end());
    vector<int> order;
    for (int i = 0; i < N; i++) {
        mp[xp[i][2]][0] = i;
        mp[yp[i][2]][1] = i;
    }
    // for (int i = 0; i < N; i++) {
    //     cout << xp[i][2] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < N; i++) {
    //     cout << yp[i][2] << " ";
    // }
    // cout << "\n";
    //oh everything is perpendicular
    //sort by x, sort by y
    //fuck it we toposort
    //we require filling to, order, pos, dist

    //we can go up or go right, let's go right >:(
    long dist = 0;
    int now = xp[0][2];
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        order.push_back(now);
        visited[now] = true;
        to[i] = dist;
        pos[now] = i;
        vector<array<int, 3>> &use = !(i % 2) ? yp : xp;
        int ind = mp[now][!(i % 2)];
        int nxt = ind + (ind % 2 ? -1 : 1);
        dist += abs(use[ind][1] - use[nxt][1]);
        now = use[nxt][2];
    }
    //ok that is done
    //thus we have formed a loop and all the different things, as well as an order
    //now we want to find for any point what two points is it in between?
    //find if there are solutions for vertically oriented vs horizontally, and if there are
    //which are on a segment and which are not
    //find == x and < y

    //okay so we want to ultimately find for x, y the index of the segment going ccw
    //that contains it. that's it
    //bug bug bug bug bug
    auto check = [&](vector<array<int, 3>> &use, int x, int y) {
        int s = 0, e = N;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (use[m][0] < x || (use[m][0] == x && use[m][1] <= y)) { s = m; }
            else { e = m; }
        }
        // cout << s << endl;
        //if we are on a point, return now
        //otherwise, we are in between something
        if (use[s][0] == x && use[s][1] == y) { return pos[use[s][2]]; }
        if (s + 1 == N) { return -1; }
        if (use[s][0] != x) { return -1; }
        if (use[s][0] != use[s+1][0]) { return -1; }
        //now return the smallest one to which we belong
        //oh this is the loop glitch again
        int poss = pos[use[s][2]], pos1 = pos[use[s+1][2]];
        if (poss > pos1) { swap(poss, pos1); }
        if (poss == 0 && pos1 == N - 1) { return N - 1; }  //go forwards
        if (pos1 - poss != 1) { return -1; }
        return poss;
    };
    // cout << "\n";
    vector<int> diff(2 * N + 1);
    for (int i = 0; i < C; i++) {
        int one, two;
        int x1, y1; cin >> x1 >> y1;
        int x2, y2; cin >> x2 >> y2;
        one = max(check(xp, x1, y1), check(yp, y1, x1));
        two = max(check(xp, x2, y2), check(yp, y2, x2));
        // cout << one << " " << two << endl;
        // assert(one != -1 && two != -1);  //bug DETECTED
        if (one > two) { swap(one, two); swap(x1, x2); swap(y1, y2); }
        long bruh = 0;
        //distance is correct
        if (one == two) { bruh = abs(x2 - x1) + abs(y2 - y1); }
        else {
            bruh = to[two] - to[one];
            int x = xp[mp[order[one]][0]][0], y = yp[mp[order[one]][1]][0];
            bruh -= abs(x1 - x) + abs(y1 - y);
            x = xp[mp[order[two]][0]][0], y = yp[mp[order[two]][1]][0];
            bruh += abs(x2 - x) + abs(y2 - y);
        }
        // cout << one << " " << two << "\n";
        //what are all possible cases?
        if (bruh < dist / 2) {
            //if one is on point decrease by one
            //if one == two continue
            int x = xp[mp[order[one]][0]][0], y = yp[mp[order[one]][1]][0];
            if (x1 == x && y1 == y) { one--; }
            if (one == two) { continue; }
            //now all of [l, r] is covered, holy shit
            //wait why tf is this being wrong what
            // cout << one << " " << two << "\n";
            diff[one + 1]++;
            diff[two + 1]--;
        }   else {
            //we need to go the other way what the fricking heck
            int x = xp[mp[order[two]][0]][0], y = yp[mp[order[two]][1]][0];
            if (x2 == x && y2 == y) { two--; }
            // cout << one + N << " " << two << "\n";
            diff[two + 1]++;
            diff[one + N + 1]--;
        }
    }
    vector<int> res(N);
    int cur = 0;
    for (int i = 0; i < 2 * N; i++) {
        cur += diff[i];
        res[i % N] += cur;
    }
    for (int i = 0; i < N; i++) {
        cout << res[pos[i]] << "\n";
    }
}