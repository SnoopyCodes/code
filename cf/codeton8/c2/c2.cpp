#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    
    vector<int> chosen;
    vector<bool> used;
    chosen.resize(X);
    used.resize(X);
    for (int i = 0; i < X; i++) {
        int x; cin >> x; x--;
        chosen[i] = x;
    }
    int total = 0;  //# trits alr formed
    int use = 0;  //form stuff
    vector<bool> del(X);
    sort(chosen.begin(), chosen.end());
    //is it easier to add before or after?
    //if we add after it is arguably easier?
    //we want every point we add to give an extra triangle at least
    //so delete first add after
    //GG
    //we should also not add on deleted points.
    int deleted = 0;
    int placed = 0;
    for (int i = 0; i < X; i++) {
        if (i+1 != X && chosen[i+1] - chosen[i] == 2) {
            total++;
            placed++;
            continue;
        }   else if (i+1 == X && chosen[i] - chosen[0] == N-2) {
            total++;
            placed++;
            break;
        }
        if (i+1 == X) { break; }
        if (i + 2 != X && chosen[i+2] - chosen[i] == 2 && !used[i+1]) {
            used[i+2] = true;
            total++;
            placed++;
            del[i+1] = true;
            deleted++;
        }   else if (i + 2 == X && chosen[i] - chosen[0] == N - 2 && !used[i+1]) {
            total++;
            placed++;
            used[i+2] = true;
            del[i+1] = true;
            deleted++;
        }
    }
    cout << total + X - 2 << "\n";
    int p = 0;
    vector<int> newv(X-deleted);
    for (int i = 0; i < X; i++) {
        if (del[i]) { continue; }
        newv[p] = chosen[i];
        p++;
    }
    X -= deleted;
    int add = 0;
    map<int, bool> put;
    if (Y != 0 && newv[X-1] < N + newv[0] - 2) {
        int pos = newv[0] - 2 >= 0 ? newv[0] - 2 : N + newv[0] - 2;
        put[pos] = true;
        total+= 2;
        Y--;
        //check if this works for the others
        if (newv[X-1] - pos == 2 || N - newv[X-1] + pos == 2) { total++; }
    }
    if (Y != 0 && newv[1] > newv[0] + 2) {
        put[newv[0] + 2] = true;
        total+= 2;
        Y--;
        if (newv[1] - newv[0] - 2 == 2) { total++; }
    }
    for (int i = 1; Y != 0 && i < X - 1; i++) {
        if (newv[i] - newv[i-1] > 2 && !put[newv[i]-2] && !put[newv[i]-1]) {
            put[newv[i]-2] = true;
            total += 2;
            Y--;
        }
        if (i+1 != X && newv[i+1] - newv[i] > 2 && !put[newv[i]+2] && !put[newv[i]+1]) {
            put[newv[i]+2] = true;
            total += 2;
            Y--;
            if (newv[i+1] - newv[i] - 2 == 2) { total++; }
        }
    }
    //the extra y points are ineffective when the points we put them on already have been counted
    //so if the total points - placed - X + deleted = a
    //we can only have a extra
    cout << total << " " << X << " " << Y << " " << placed << " " << deleted << "\n";
    cout << total + X - 2 + min(Y, N - placed - X + deleted) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}