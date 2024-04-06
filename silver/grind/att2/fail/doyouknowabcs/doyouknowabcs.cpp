#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v;
set<tuple<ll, ll, ll>> triples;
bool check(ll a, ll b, ll c, const vector<ll> &vs) {
    if (a <= 0 || b <= 0 || c <= 0) { return false; }
    if (a > b || a > c || b > c) { return false; }
    if (vs[3]) { if (a + b != vs[3]) { return false; }}
    if (vs[4]) { if (a + c != vs[4]) { return false; }}
    if (vs[5]) { if (b + c != vs[5]) { return false; }}
    if (vs[6]) { if (a + b + c != vs[6]) { return false; }}
    if (triples.find({a, b, c}) != triples.end()) { return false; }
    triples.insert({a, b, c});
    cout << "yes" << "\n";
    cout << a << " " << b << " " << c << "\n";
    return true;
}
bool find(int combo) {
    bitset<7> bs(combo);
    vector<ll> vs(7);
    int p = 0;
    for (int i = 0; i < 7; i++) { if (bs[i]) { vs[i] = v[p]; p++; } cout << bs[i]; }
    cout << "\n";
    ll a = vs[0], b = vs[1], c = vs[2];
    if (!a && !b && !c) {
        a = vs[6] - vs[5];
        b = vs[6] - vs[4];
        c = vs[6] - vs[3];
        return check(a, b, c, vs);
    }
    if (a) {
        if (!b && bs[3]) { b = vs[3] - a; }
        if (!c && bs[4]) { c = vs[4] - a; }
        //i think we are now guaranteed to have at least 2
        if (a && b && c) { return check(a, b, c, vs); }
        //guaranteed to have 2
        if (b) {
            if (bs[5]) { c = vs[5] - b; }
            else { c = vs[6] - a - b; }
        }   else {
            if (bs[5]) { b = vs[5] - c; }
            else { b = vs[6] - a - c; }
        }
        return check(a, b, c, vs);
    }
    if (b) {
        if (!a && bs[3]) { a = vs[3] - b; }
        if (!c && bs[5]) { c = vs[5] - b; }
        if (a && b && c) { return check(a, b, c, vs); }
        if (a) {
            if (bs[4]) { c = vs[4] - a; }
            else { c = vs[6] - a - b; }
        }   else {
            if (bs[4]) { a = vs[4] - c; }
            else { a = vs[6] - b - c; }
        }
        return check(a, b, c, vs);
    }
    if (!a && bs[4]) { a = vs[4] - c; }
    if (!b && bs[5]) { b = vs[5] - c; }
    if (a && b && c) { return check(a, b, c, vs); }
    if (a) {
        if (bs[3]) { b = vs[3] - a; }
        else { b = vs[6] - a - c; }
    }   else {
        if (bs[3]) { a = vs[3] - b; }
        else { a = vs[6] - b - c; }
    }
    return check(a, b, c, vs);
}
void solve() {
    int N; cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) { cin >> v[i]; }
    //can we brute force this?
    //lets say we get 4 numbers
    //7 choose 4 is not a lot of combinations
    //these numbers must be positive
    //if we sort it it will be in order a, b, c, a+b, a+c, b+c, a+b+c
    //oh bruh we have to consider
    //a+b can be less than c
    //is that it though
    //i think so
    int total = 0;
    int valid = 0;
    sort(v.begin(), v.end());
    for (int combo = 0; combo < 128; combo++) {
        if (__popcount(combo) == N) {
            total += find(combo);
        }
    }
    {
        int tmp = v[2];
        v[2] = v[3];
        v[3] = v[2];
    }
    cout << "split" << "\n";
    for (int combo = 0; combo < 128; combo++) {
        if (__popcount(combo) == N) {
            total += find(combo);
        }
    }
    cout << total << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}