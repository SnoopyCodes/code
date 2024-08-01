#include <bits/stdc++.h>

using namespace std;
struct 朋友 {
    int p, c, x;
};
vector<朋友> pyq;
bool comp(朋友 py1, 朋友 py2) {
    return py1.x < py2.x;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, A, B; cin >> N >> A >> B;
    pyq.resize(N);
    //
    // the cost of one friend
    // Ci - Xi * x
    for (int i = 0; i < N; i++) {
        cin >> pyq[i].p >> pyq[i].c >> pyq[i].x;
    }
    // at this point just go for n^3 wtf
    // or n^4
    // this is quite challenging
    // we can set up like a 3d matrix
    // [f][m][c]: friend we are on, money, cones;
    // then the value given is the popularity thus far
    // murderous, isn't it?
    // wait n^4 is the 8-10 subtask isnt it
    // goddamn it
    // if we sort by mooney cost though..
    // ice cream?
    // wait we should try sorting by ice cream cost
    // yes
    // we may only choose one cow to give ice cream to
    // wait we have like
    // an optimal selection right
    // afterwards we can select some friend to bribe a bit more
    // if we consider B to be 0
    // 
    sort(pyq.begin(), pyq.end(), comp);
    // [friend][money spent] = max popularity? i think
    // 
    vector<vector<int>> gx(N + 1, vector<int>(A + B + 1, -1));
    for (int i = 0; i < N; i++) {
        //first try spending all here
        int cost = pyq[i].c - min(B / pyq[i].x, pyq[i].c);
        // now we move onwards
        // oh wait we must consider that where it is not yet spent
        // 
        for (int j = 0; j <= A; j++) {
            if (gx[i][j] == -1) { continue; }
            gx[i+1][j] = max(gx[i+1][j], gx[i][j]);
        }
    }
}