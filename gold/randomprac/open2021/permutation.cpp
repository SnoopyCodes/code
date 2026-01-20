#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
int N;
ii<2> pt[40];
int dp[41][40][40][40];
int inside[40][40][40];
#define x [0]
#define y [1]

struct line {
    double m;
    double b;
    bool vert = false;
    line(int x1, int y1, int x2, int y2) {
        if (x1 == x2) {
            b = x1;
            vert = true;
            return;
        }
        m = (double) (y2 - y1) / (x2 - x1);
        b = - m * x1 + y1;
    }
    double at(int z) {
        if (vert) {
            assert(b != z);
            return MOD;
        }
        return m * z + b;
    }
};

bool in(int i, int j, int k, int p) { //is p inside (i, j, k)
    //thanks uil
    //we can raycast, but that requires segment intersection?
    //fine. raycast x = p.x going DOWN
    {
        int a = min({ i, j, k });
        int c = max({ i, j, k });
        int b = i + j + k - a - c;
        i = a, j = b, k = c;
    }
    assert(p != i && j != p && k != p);
    //oh no 3 are collinear good

    line ij = line(pt[i] x, pt[i] y, pt[j] x, pt[j] y);
    line jk(pt[j] x, pt[j] y, pt[k] x, pt[k] y);
    line ik(pt[i] x, pt[i] y, pt[k] x, pt[k] y);
    bool f = i == 1 && j == 2 && k == 4 && p == 3;

    int ct = 0;
    int xx = pt[p] x;
    int yy = pt[p] y;
    if (ij.at(xx) <= yy && pt[i] x <= xx && xx <= pt[j] x) ct++;
    if (jk.at(xx) <= yy && pt[j] x <= xx && xx <= pt[k] x) ct++;
    if (ik.at(xx) <= yy && pt[i] x <= xx && xx <= pt[k] x) ct++;
    // if (f) {
    //     cout << "pt " << pt[p] x << " " << pt[p] y << "\n";
    //     cout << i << " " << j << " " << k << "\n";
    //     cout << "i " << pt[i] x << " " << pt[i] y << "\n";
    //     cout << "j " << pt[j] x << " " << pt[j] y << "\n";
    //     cout << "k " << pt[k] x << " " << pt[k] y << "\n";
    //     cout << ik.at(1) << "\n";
    //     cout << ij.at(xx) << "\n";
    //     cout << jk.at(xx) << "\n";
    //     cout << ik.at(xx) << "\n";
    //     cout << ct << "\n";
    // }
    if (pt[j] x == pt[p] x) { //special case
        if (pt[j] y < pt[p] y) {
            return ik.at(xx) > yy;
        }   else {
            return ik.at(xx) < yy;
        }
    }
    return ct == 1;

}
//0, 2, 4, 3
ii<3> ext(int i, int j, int k, int p) { //can we extend? returns outside points
    int outlier = -1;
    if (in(j, k, p, i)) {
        i = p;
    }   else if (in(i, k, p, j)) {
        j = p;
    }   else if (in(i, j, p, k)) {
        k = p;
    }   else {
        return { -1, -1, -1 };
    }
    return ii<3>{ min({ i, j, k }), i+j+k-min({i,j,k})-max({i,j,k}), max({ i, j, k }) };
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*
    very special problem
    this is going to be cursed dp isnt it
    40 * 39 * 38 / 6 = 20 * 13 * 19 ~ 400 * 15 = 6000
    6000 different triangles
    we can pairwise check these...
    we can check for each triangle the points that it cannot allow
    (cannot extend to)
    and the points that lie within it.
    okay..
    i assume the answer isnt just 3! * allowed triangles * (N - 3)! ?
    treat each of the triangles as a node, and it can "grow" (transition) to others
    this is a lowkey a cool dp problem, try it (do i tle? i hope not)
    dp[used nodes][i][j][k] use arrays cause yes small vector bad
    consider being less stupid
    how do we deal with the.. ordering internals? we can insert them at any time
    we have like x nodes of growth, and internal growths of y before each.
    is it possible to math the transition???? stars and bars????
    no.
    dp[i][j][k][remaining_internal_nodes]?
    this is looking the most likely...
    actually yeah.
    for used nodes:
        for i:
            for j:
                for k:
                    for other_node:
    actually idk how to count "for used nodes?"
    screw it.
    */

    cin >> N;
    rep(i, 0, N) {
        cin >> pt[i] x >> pt[i] y;
    }
    sort(pt, pt + N); //does this help me at all? idfk man
    //update: it does
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            rep(k, j + 1, N) {
                int in_count = 0;
                bool f = i == 0 && j == 2 && k == 4;
                rep(l, i + 1, k) {
                    if (l == j) {
                        continue;
                    }
                    //check if inside trit
                    in_count += in(i, j, k, l);
                }
                // cout << i << " " << j << " " << k << " " << in_count << "\n";
                // if (i == 1 && j == 2 && k == 4) {
                //     cout << pt[i] x << " " << pt[i] y << "\n";
                //     cout << pt[j] x << " " << pt[j] y << "\n";
                //     cout << pt[k] x << " " << pt[k] y << "\n";
                // }
                inside[i][j][k] = in_count;
                dp[3][i][j][k] = 6;
            }
        }
    }

    rep(used, 3, N) {
        // cout << "round " << used << "\n";
        rep(i, 0, N) {
            rep(j, i + 1, N) {
                rep(k, j + 1, N) {
                    if (!dp[used][i][j][k]) {
                        continue;
                    }
                    // cout << i << " " << j << " " << k << " has " << dp[used][i][j][k] << "\n";
                    rep(l, 0, N) {
                        if (l == i || l == j || l == k) {
                            continue;
                        }
                        auto [ii, jj, kk] = ext(i, j, k, l);
                        bool can_trans = ii != -1;
                        if (can_trans) {
                            //the next state gains stuff
                            // cout << i << " " << j << " " << k << " trans to " << ii << " " << jj << " " << kk << "\n";
                            (dp[used + 1][ii][jj][kk] += dp[used][i][j][k]) %= MOD;
                        }
                    }
                    if (used < inside[i][j][k] + 3) {
                        (dp[used + 1][i][j][k] += dp[used][i][j][k] * (inside[i][j][k] + 3 - used) % MOD) %= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            rep(k, j + 1, N) {
                ans = max(ans, dp[N][i][j][k]);
            }
        }
    }
    cout << ans << "\n";

}