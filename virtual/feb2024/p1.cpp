#include <bits/stdc++.h>

using namespace std;


vector<array<int, 2>> posp;
vector<array<int, 2>> negp;
vector<int> linep;
void solve() {
    int N, X; cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int y1, y2, x2; cin >> y1 >> y2 >> x2;
        posp.push_back({x2, y1});
        negp.push_back({x2, y1});
        linep.push_back(y1);
        linep.push_back(y2);
    }
    //we want to move points through the thing
    //we need to first guarantee that targets will move down like
    //choose N cows for right top, and N for right bottom
    //why does this work?
    //first sort the negative cows, then the positive cows
    //why cant you just sort and then like
    //throw the lowest on the thing
    //im so confused
    //so first of all there are just points on a line
    //and then there are positive and negative points
    //so thats why we need bsearch for those points okay
    //for cows
    vector<int> poscows;
    vector<int> negcows;
    for (int i = 0; i < 4 * N; i++) {
        int c; cin >> c;
        if (c > 0) {
            poscows.push_back(c);
        }   else {
            negcows.push_back(c);
        }
    }
    if (poscows.size() < N || negcows.size() < N) {
        cout << -1 << "\n";
        return;
    }
    //remove until we have the cows with least slope from poscows
    vector<int> maincows;
    sort(poscows.begin(), poscows.end());
    sort(negcows.begin(), negcows.end(), greater<int>());
    while (poscows.size() > N) {
        maincows.push_back(poscows[poscows.size() - 1]);
        poscows.pop_back();
    }
    while (negcows.size() > N) {
        maincows.push_back(negcows[negcows.size() - 1]);
        negcows.pop_back();
    }
    sort(maincows.begin(), maincows.end());
    sort(linep.begin(), linep.end());
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}