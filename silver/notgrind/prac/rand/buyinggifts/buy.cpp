#include <bits/stdc++.h>
#define ll long long

using namespace std;
//wait ok lets see
//search for the largest pair with the smallest difference? and sort?
//and then we should binary search for the largest pair that works
//wait do we first linearly run through the entire thing 
//lets say we directly just sort it first thats a bad idea
//this would work if we could find all the pairs but why would we even do that that takes too long
//unless we were to put all the values into a thing and then sort it
//and then we can iterate through it and find the closest pairs?
//then we can sort by smallest difference and binary search from there
//you know a sorted set might come in handy right here
vector<pair<int, int>> f1;
vector<pair<int, int>> f2;
vector<int> combined;
bool comp(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p1.second) < abs(p2.first - p2.second);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "\n";
        int n; cin >> n;
        f1.resize(n);
        f2.resize(n);
        for (int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            f1[i].first = a; f2[i].first = b;
            f1[i].second = f2[i].second = i;
            combined.push_back(a); combined.push_back(b);
        }
        sort(f1.begin(), f1.end(), greater<int>());
        sort(f2.begin(), f2.end(), greater<int>());
        sort(combined.begin(), combined.end(), greater<int>());
        
    }
}