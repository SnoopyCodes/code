#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> tickets;
ll N, K;
array<int, 2> prog1;
array<int, 2> prog2;
bool valid(int g) {
    int p1 = g / prog1[1];
    int p2 = g / prog2[1];
    int inter = g / (prog1[1] * prog2[1]);
    p1 -= inter; p2 -= inter;
    ll amt = min(inter, g);
    ll total = 0;
    g -= amt;
    int i = 0;
    while (i < amt) {
        total += (prog1[0] + prog2[0]) * tickets[i];
        i++;
    }
    i = amt;
    amt = min(p1, g);
    g -= amt;
    amt += i;
    while (i < amt) {
        total += prog1[0] * tickets[i];
        i++;
    }
    amt = min(p2, g);
    amt += i;
    while (i < amt) {
        total += prog2[0] * tickets[i];
        i++;
    }
    return total >= K;
}
void solve() {
    cin >> N;
    tickets.clear(); tickets.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> tickets[i];
        tickets[i] /= 100;
    }
    cin >> prog1[0] >> prog1[1] >> prog2[0] >> prog2[1];
    if (prog1 < prog2) { swap(prog1, prog2); }
    cin >> K;
    int s = 0, e = N;
    //find the smallest index so it works
    sort(tickets.begin(), tickets.end(), greater<int>());
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (valid(m)) {
            e = m;
        }   else {
            s = m;
        }
    }
    if (!valid(e)) {
        cout << -1 << "\n";
    }   else {
        cout << e << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q; while (Q) { Q--; solve(); }
}