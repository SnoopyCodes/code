#include <bits/stdc++.h>

using namespace std;
int N;
int C;
vector<int> cows;
vector<bool> appear(1e6);
bool comp(int c1, int c2) {
    return __popcount(c1) < __popcount(c2);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C >> N;
    cows.resize(N);
    //we can compress it into a bitset or an integer
    //and then compare and popcount to find the distance
    //and then we need to do that for all barns
    //not easy
    //
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int total = 0;
        for (int j = 0; j < C; j++) {
            total += ((s[j] == 'G') << j);
        }
        appear[total] = true;
        cows[i] = total;
        cout << cows[i] << "\n";
    }
    sort(cows.begin(), cows.end(), comp);
    cout << __popcount(cows[0] ^ cows[N-1]);
    for (int i = 1; i < N; i++) {
        //now check the one next to us
        
    }
    //so we have integers
    //and then we can check their relation to another in O(1) time
    //we have barns
    //and we need to find the furhtest diff
    //what if we all connect to 0 from which we sort
    //and then 0 checks if it has any neighbors for which it has the differences asked
    //
}