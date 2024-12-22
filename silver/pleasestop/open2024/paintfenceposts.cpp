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
    vector<bool> visited(N);
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
    //start at leftmost btotom most and you have to go right and down as much as you can
    //we HAVE to go DOWN
    long dist = 0;
    int ind = 0;
    int now = xp[0][2];
    bool dir = false;
    int cov = 0;
    int last;
    //i understand it now
    //we need to continuously check the ones around and see if they have only one neighbor
    //after removal of this one
    auto count = [&](bool d, int x) {
        int cnt = 0;
        vector<array<int, 3>> &uh = !d ? xp : yp;
        if (mp[x][d] + 1 < N && uh[mp[x][d]][0] == uh[mp[x][d]+1][0] && !visited[uh[mp[x][d]+1][2]]) { cnt++; }
        if (mp[x][d] > 0 && uh[mp[x][d]][0] == uh[mp[x][d]-1][0] && !visited[uh[mp[x][d]-1][2]]) { cnt++; }
        return cnt;
    };
    while (true) {
        cov++;
        pos[now] = ind;
        order.push_back(now);
        visited[now] = true;
        to[ind] = dist;
        if (cov == N) { break; }
        vector<array<int, 3>> &use = dir ? xp : yp;  //we want the same of
        int curi = mp[now][dir ? 0 : 1];
        //now we must do stuff
        //just consider the x go right case
        //if possible, increase
        // cout << curi << "\n";
        int nxt;
        if (curi > 0 && count(dir, use[curi-1][2]) == (cov == N - 1 ? 0 : 1) && use[curi-1][0] == use[curi][0]) { nxt = curi - 1; }
        else { nxt = curi + 1; }
        dist += abs(use[nxt][1] - use[curi][1]);
        now = use[nxt][2];
        last = now;
        ind++;
        dir = !dir;
    }
    bool chk = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { chk = false; }
    }
    if (!chk) {
        cov = 0;
        dist = 0;
        dir = true;
        now = xp[0][2];
        ind = 0;
        while (true) {
            cov++;
            pos[now] = ind;
            order.push_back(now);
            visited[now] = true;
            to[ind] = dist;
            if (cov == N) { break; }
            vector<array<int, 3>> &use = dir ? xp : yp;
            int curi = mp[now][dir ? 0 : 1];
            int nxt;
            if (curi > 0 && count(dir, use[curi-1][2]) == (cov == N - 1 ? 0 : 1) && use[curi-1][0] == use[curi][0]) { nxt = curi - 1; }
            else { nxt = curi + 1; }
            dist += abs(use[nxt][1] - use[curi][1]);
            now = use[nxt][2];
            last = now;
            ind++;
            dir = !dir;
        }
    }
    for (int i = 0; i < N; i++) {
        assert(visited[i]);
    }
    now = xp[0][2];
    dist += abs(xp[mp[now][0]][0] - xp[mp[last][0]][0] + abs(yp[mp[now][1]][0] - yp[mp[last][1]][0]));
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
            if (use[m][0] <= x && use[m][1] <= y) { s = m; }
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
        if (poss == 0 && pos1 == N - 1) { return N - 1; }  //forwards
        else if (pos1 - poss != 1) { return -1; }
        return min(pos[use[s][2]], pos[use[s+1][2]]);
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