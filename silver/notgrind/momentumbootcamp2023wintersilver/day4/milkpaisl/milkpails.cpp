#include <bits/stdc++.h>

using namespace std;
int X, Y, K, M;
int best = INT_MAX;
bool visited[101][101];
void action(int p1, int p2, int a) {  //pail 1, pail 2, actions so far
    if (visited[p1][p2]) { return; } //we have been to this state before
    if (a > K) { return; }
    best = min(best, abs(p1 + p2 - M));
    visited[p1][p2] = true;
    action(X, p2, a+1);
    action(p1, Y, a+1);
    action(0, p2, a+1);
    action(p1, 0, a+1);
    //1 into 2
    if (p1 + p2 > X) {
        action(X, p2 - (X - p1), a+1);
    }   else {
        action(p1+p2, 0, a+1);
    }
    //2 into 1
    if (p1 + p2 > Y) {
        action(p1 - (Y-p2), Y, a+1);
    }   else {
        action(0, p1+p2, a+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> X >> Y >> K >> M;
    /*
    we can work with the values of X, Y, and |x-y|
    we can brute force all the possibilities?
    100^3 is freedom lmfao
    */
   action(0, 0, 0);
   cout << best << "\n";
}