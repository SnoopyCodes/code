#include <bits/stdc++.h>

using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) { return p1.first < p2.first; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    //so we can have N^2 (and probably log n)
    //so theyre all distinct... that helps i think
    //this is likely a sorted set probelm
    //how do we tell if two points can be together?
    //its all about what can and cant be together
    //this might be 2 pointers??
    //we can use sets for x and y
    //so for any pair of points (x, y) and (x2, y2) where x2 > x && y2 > y,
    //any points with x-coord > x2 && y-coord > y2 must certainly be invalid
    //first brute force i guess
    //sort and 
    //pick a point and keep a list of what y's that it has went through
    //then track back and just ok sure
    long long sub = 0;
    sort(cows.begin(), cows.end(), compare);
    for (int i = 0; i < N-1; i++) {
        set<int> m;
        for (int j = i+1; j < N; j++) {
            auto it = lower_bound(m.begin(), m.end(), cows[i].second);
            int count = distance(m.begin(), it);  //there only needs to be 1 for confirmation though. 
            cout << count << "\n";
            sub += count;
            //so if the number is 1, then we can't connect 1 box
            //if the number is 2, we can't connect 3 boxes
            //if the number is 3, we can't connect ...
            m.insert(cows[j].second);
        }
        //so definitely coord compress, take it by the x's...0-2499
    }
    cout << sub;
}