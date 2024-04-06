#include <bits/stdc++.h>

using namespace std;
struct f {
    int pos, sudu;
};
bool comp(f f1, f f2) {
    return f1.pos < f2.pos;
}
vector<f> fs;
bool location(double loc, double sj) {
    //check if everything less than loc is covered
    //do we have to sort by speed or anything if coord is the same?
    for (int i = 0; i < fs.size() && fs[i].pos < loc; i++) {
        if (fs[i].sudu * sj < loc - fs[i].pos) { return false; }
    }
    return true;
}
bool timer(double sj) {
    double s = 0, e = 1e9+1;
    //find the largest s so that 
    while (e > s + 1e-7) {
        double m = (s + e) / 2;
        if (location(m, sj)) { s = m; }
        else { e = m; }
    }
    double loc = s;
    for (int i = 0; i < fs.size(); i++) {
        if (fs[i].sudu * sj < abs(fs[i].pos - loc)) { return false; }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    fs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> fs[i].pos;
    }
    for (int i = 0; i < n; i++) {
        cin >> fs[i].sudu;
    }
    sort(fs.begin(), fs.end(), comp);
    double s = 0, e = 1e9+1;  //e is minimum time
    //find the min value of e
    //this is so sad
    while (e > s + 1e-7) {
        double m = (s + e) / 2;
        if (timer(m)) { e = m; }
        else { s = m; }
    }
    cout.precision(12); cout << e << "\n";
}