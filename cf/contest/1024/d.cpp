#include <bits/stdc++.h>

using namespace std;

int pos(vector<int> &p, int x) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == x) { return i; }
    }
    return -1;
}
bool finpos(vector<int> &p, vector<int> &b) {
    int first = pos(p, b[b.size() - 2]);
    int second = pos(p, b[b.size() - 1]);
    int first_tie = first < p.size() ? p[first + 1] : -1;
    int second_tie = second < p.size() ? p[second + 1] : -1;
    //if first_tie is greater than second then it goes down later so no swap so in order
    return first_tie < second_tie - 1;
}

void solve() {
    int N; cin >> N;
    //swapping by 2s
    vector<int> a, b, P(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        P[i] = x;
        if (i % 2 == 0) { a.push_back(x); }
        else { b.push_back(x); }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (!finpos(P, N % 2 == 0 ? b : a)) { swap(b[b.size() - 2], b[b.size() - 1]); }
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { cout << a[i / 2]; }
        else { cout << b[i / 2]; }
        cout << " \n"[i == N - 1];
    }
    //find relative ordering of last 4
    //these will not move relative to each other unless they are tied to another thing?
    //find the positions of "a".
    //5 4 3 2 1
    //5 2 1 4 3
    //help help help help help
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}