#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    string s; cin >> s;
    //so the rest of the string p+1... N must already be cyclic
    vector<array<int, 2>> compress;
    map<int, int> sizes;
    for (int i = 0; i < N; i++) {
        //so we need to reverse it and then do a shift
        //this is hard help
        //sooo what is htis
        //just figure out if our thing, when reversed and conjoined to the end
        //forms k-proper, and the rest of the string itself forms k-proper
        //how does the end thing transform into different types of k-proper?
        //i think this is an impl problem
        //track group at end and front
        //we should compress it into groups of 0's and 1's
        //we can use a multiset of sizes to track remaining different sizes?
        int cnt = 1;
        while (i + 1 < N && s[i] == s[i+1]) {
            i++;
            cnt++;
        }
        compress.push_back({cnt, s[i] == '1'});
        sizes[cnt]++;
    }
    //process: pop the back group and the front group
    //while not all sizes in the multiset thing are the same
    //keep popping
    //technically if there are a lot of different sizes then its very over
    //there are not actually a lot of different sizes
    //wait also there needs to be a factor number of things
    //we shouldve just iterated over number of groups and seen if that worked or not :/
    int k = -1;
    string perma = "";
    array<int, 2> back = compress[compress.size()-1];
    array<int, 2> front = compress[0];
    cout << (back[1] == front[1]) << "\n";
    compress.erase(compress.begin());
    compress.pop_back();
    int p = front[0];
    set<int> newszs;
    sizes[back[0]]--; sizes[front[0]]--;
    if (sizes[back[0]] == 0) { sizes.erase(back[0]); }
    if (sizes[front[0]] == 0) { sizes.erase(front[0]); }
    while (sizes.size() > 1) {
        newszs.insert(front[0]);
        //add the front to the front
        front = compress[0];
        compress.erase(compress.begin());
        sizes[front[0]]--;
        if (sizes[front[0]] == 0) { sizes.erase(front[0]); }
        p += front[0];
    }
    cout << (back[1] == front[1]) << "\n";
    //i hope this works
    if (newszs.size() > 1) { cout << -1 << "\n"; return; }
    //now we must check if we can add the front and the back
    if (front[1] == back[1]) {
        k = front[0] + back[0];
        if ((k == *newszs.begin() || newszs.size() == 0) && k == (*sizes.begin()).first) {
            cout << p << "\n"; return;
        }
        cout << k << " " << *newszs.begin() << " " <<  (*sizes.begin()).first << "\n";
    }
    cout << -1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}